標籤: #computer-networks 

---

[TOC]

---

The TCP service model includes a connection-oriented service and a reliable data transfer service.

- ==Connection-oriented== service.
	- TCP has the client and server exchange transport-layer control information with each other before the application-level messages begin to flow. This is called handshaking procedure.
	- After handshaking, a ==TCP connection== is established between the sockets of the two processes.
- Reliable data transfer service.
	- The communicating processes can rely on TCP to deliver all data sent without error and in the proper order.
- Provides ==full-duplex service==.
	- If there is a TCP connection between process A and B, then data can flow from A to B and B to A at the same time.
- Is ==point-to-point==.
	- Between a single sender and a single receiver.
- ==Three-way handshake==: The first two segments carry no payload, and the third of these segments may carry a payload.
- The maximum amount of data that can be grabbed and placed in a segment is limited by the ==maximum segment size(MSS)==.
	- It is set by first determining the length of the largest link-layer frame that can be sent by the local sending host (called ==maximum transmission unit==).

# Segment Structure

![[Pasted image 20221113181708.png]]

- *Source port and Dest port*: Specifies the ports.
- [[#Sequence Numbers and Acknowledgement Numbers]]: Used by TCP sender and receiver in implementing a reliable data transfer service. Each uses 32 bits.
- *Receive window*: Used for flow control. Uses 16 bits.
- *Header length field*: Specifies the length of the TCP header in in 32-bit words. Uses 4 bits.
- *Options*: When a sender and receiver negotiate the maximum segment size or as a window scaling factor for use in high-speed networks. A time-stamping option is also defined.
- *flag field*: Contains 8 bits.
	- *ACK*: Indicate that the segment contains an acknowledgment.
	- *RST*, *SYN*, *FIN*: Used for [[#Connection Management]].
	- *CWR*, *ECE*: Used in explicit congestion notification.
	- *PSH*: Indicates that the receiver should pass the data to the upper layer immediately.
	- *URG*: Used to indicate that there is data in this segment that the sending-side upper-layer has marked as "urgent".
		- The location of the last byte of this urgent data is indicated by the 16-bit ==urgent data pointer field==.

## Sequence Numbers

The **sequence number for a segment** is the byte-stream number of the first byte in the segment.

For example:

![[Pasted image 20221113195628.png]]

The sequence number of the first segment is numbered 0, and the second segment is numbered 1000.

### The Starting Sequence Number

In the above example, we see that the sequence number starts at 0. In reality, the initial sequence number is randomly choson. This *minimize the possibility that a segment that is still present in the network from earlier confuses the hosts*.

## Acknowledgement Number

The **acknowledgement number** is the sequence number of the next byte that receiver is expecting from sender.

For example, host A has received all bytes numbered 0 through 535, then the acknowledgement number in the ACK packet will be 536.

Note that the acknowledgement numbers are **cumulative acknowledgements**, meaning that the bytes before the acknowledgement number are received perfectly.

# Timeout

TCP, like our [[RDT]] protocol, uses a timeout/retransmit mechanism to recover from lost segments. Clearly, the timeout should depend on the round-trip time.

## Estimating the Round-Trip Time

Instread of measuring a `SampleRTT` for every transmitted segment, most TCP implementations take only one `SampleRTT` at a time. At any point in time, the `SampleRTT` is being estimated for only one of the transmitted but currently unacknowledged segments.

Also, TCP never computes a `SampleRTT` for a segment that has been retransmitted, it only measures `SampleRTT` for those that have been transmitted once.

TCP maintains an average, called the `EstimatedRTT`. It is calculated using the formula below.

$$\text{EstimatedRTT} = (1 - \alpha) \cdot \text{EstimatedRTT} + \alpha \cdot \text{SampleRTT}$$

> The new value of **EstimatedRTT** is a weighted combination of the previous value of **EstimatedRTT** and the new value for **SampleRTT**.

- $\alpha$: A weight. The recommended value of $\alpha$ is $\alpha = 0.125$.

This formula puts more weight on recent samples than old samples. In statistics, such an average is called an **exponential weighted moving average (EWMA)**.

In addition to estimating RTT, it is also valuable to have a measure of the variability of the RTT.

$$\text{DevRTT} = (1 - \beta) \cdot \text{DevRTT} + \vert \text{SampleRTT} - \text{EstimatedRTT} \vert$$

- $\beta$: The weight for $\text{DevRTT}$. The recommended value is $0.25$.

## Setting Timeout

It is desireable to set the timeout equal to the `EstimatedRTT` plus some margin.

$$\text{TimeoutInterval} = \text{EstimatedRTT} + 4 \cdot \text{DevRTT}$$

- An initial $\text{TimeoutInterval}$ of $1\text{ s}$ is recommended.
- If timeout occurs, the $\text{TimeoutInterval}$ will be doubled regardless of $\text{EstimatedRTT}$ and $\text{DevRTT}$.

# Reliable Data Transfer

A simplified version:

$$
\begin{array}{l}
	1 & \text{/* Assume sender is not constrained by} \\
	& \text{TCP flow or congestion control,} \\
	& \text{that data from above is less than MSS in size,} \\
	& \text{and that data transfer is in one direction only. */} \\
	2 \\
	3 & NextSeqNum = InitialSeqNumber \\
	4 & SendBase = InitialSeqNumber \\
	5 \\
	6 & \text{loop}(forever) \\
	7 & \qquad \text{switch}(event) \\
	8 \\
	9 & \qquad \qquad event\text{: data received from application above} \\
	10 & \qquad \qquad \qquad \text{create TCP }segment\text{ with sequence number } NextSeqNum \\
	11 & \qquad \qquad \qquad \text{if} (timer \text{ currently not running}) \\
	12 & \qquad \qquad \qquad \qquad \text{start } timer \\
	13 & \qquad \qquad \qquad \text{pass } segment \text{ to } IP \\
	14 & \qquad \qquad \qquad NextSeqNum = NextSeqNum + length(data) \\
	15 & \qquad \qquad \qquad \text{break} \\
	16 \\
	17 & \qquad \qquad event \text{: } timer \text{ timeout} \\
	18 & \qquad \qquad \qquad \text{retransmit not-yet-acknowledged } segment \text{ with} \\
	& \qquad \qquad \qquad \qquad \text{smallest sequence number} \\
	19 & \qquad \qquad \qquad \text{start } timer \\
	20 & \qquad \qquad \qquad \text{break} \\
	21 \\
	22 & \qquad \qquad event \text{: } \text{ACK received, with ACK field value of }y \\
	23 & \qquad \qquad \qquad \text{if}(y > SendBase) \\
	24 & \qquad \qquad \qquad \qquad SendBase = y \\
	25 & \qquad \qquad \qquad \qquad \text{if}(\text{there are currently any not-yet-acknowledged segments}) \\
	26 & \qquad \qquad \qquad \qquad \qquad \text{start } timer \\
	27 & \qquad \qquad \qquad \text{break}
\end{array}
$$

The timer management is hard. Thus, the TCP timer management procedures use only a *single* retransmission timer.

## Fast Retransmit

Because a sender often sends a large number of segments back to back, if one segment is lost, there will likely be many back-to-back duplicate ACKs.

If the sender receives three duplicate ACKs for the same data, it can take this as an indication that the segment following the segment that has been ACKed three times has been lost.

In the case that three duplicate ACKs are received, the sender performs a **fast retransmit**, retransmitting the missing segment *before* the timer expires.

Using fast retransmit, one of the event is replaced:

$$
\begin{array}{l}
	1 & \text{/* Assume sender is not constrained by} \\
	& \text{TCP flow or congestion control,} \\
	& \text{that data from above is less than MSS in size,} \\
	& \text{and that data transfer is in one direction only. */} \\
	2 \\
	3 & NextSeqNum = InitialSeqNumber \\
	4 & SendBase = InitialSeqNumber \\
	5 \\
	6 & \text{loop}(forever) \\
	7 & \qquad \text{switch}(event) \\
	8 \\
	9 & \qquad \qquad event\text{: data received from application above} \\
	10 & \qquad \qquad \qquad \text{create TCP }segment\text{ with sequence number } NextSeqNum \\
	11 & \qquad \qquad \qquad \text{if} (timer \text{ currently not running}) \\
	12 & \qquad \qquad \qquad \qquad \text{start } timer \\
	13 & \qquad \qquad \qquad \text{pass } segment \text{ to } IP \\
	14 & \qquad \qquad \qquad NextSeqNum = NextSeqNum + length(data) \\
	15 & \qquad \qquad \qquad \text{break} \\
	16 \\
	17 & \qquad \qquad event \text{: } timer \text{ timeout} \\
	18 & \qquad \qquad \qquad \text{retransmit not-yet-acknowledged } segment \text{ with} \\
	& \qquad \qquad \qquad \qquad \text{smallest sequence number} \\
	19 & \qquad \qquad \qquad \text{start } timer \\
	20 & \qquad \qquad \qquad \text{break} \\
	21 \\
	22 & \qquad \qquad event \text{: } \text{ACK received, with ACK field value of }y \\
	23 & \qquad \qquad \qquad \text{if}(y > SendBase) \\
	24 & \qquad \qquad \qquad \qquad SendBase = y \\
	25 & \qquad \qquad \qquad \qquad \text{if}(\text{there are currently any not-yet-acknowledged segments}) \\
	26 & \qquad \qquad \qquad \qquad \qquad \text{start } timer \\
	27 & \qquad \qquad \qquad \text{else // a duplicate ACK for already ACKed segment} \\
	28 & \qquad \qquad \qquad \qquad \text{number of duplicate ACKs received for }y \text{+=1} \\
	29 & \qquad \qquad \qquad \qquad \text{if (number of duplicate ACKs for }y==3) \\
	30 & \qquad \qquad \qquad \qquad \qquad \text{// TCP fast retransmit} \\
	31 & \qquad \qquad \qquad \qquad \qquad \text{resend segment with sequence number }y \\
	32 & \qquad \qquad \qquad \text{break}
\end{array}
$$

## Selective Acknowledgement

We discussed about [[RDT#Go-Back-N]] and [[RDT#Selective Repeat]]. 

The TCP sender need only maintain the smallest sequence number of a transmitted but unacknowledged byte and the next number to be sent. This sounds like **go-back N**.

But many TCP implementations will buffer correctly received but out-of-order segments. And the go-back N protocol will transmit **all** packets in the window when timeout, but TCP would transmit at most one segment.

A new protocol type is therefore defined for TCP. It is called **selective acknowledgement**.

# Flow Control

Recall that the hosts on each side of a TCP connection set aside a receive buffer for the connection. If the application is relatively slow at reading the data, the sender can very easily overflow the connection's receive buffer by sending data too quickly.

TCP provides a **flow control service** to prevent the problem. TCP let the *sender* maintain a variable $receiveWindow$ which indicates the free buffer space at the receiver.

## Procedure

Let's look at an example which host A is sending a large file to host B. Host B denote its buffersize $RcvBuffer$. Define the following variables:

- $LastByteRead$: The number of the last byte read by the application.
- $LastByteRcvd$: The number of the last byte arrived from the link.

To not overflow the buffer, 

$$LastByteRcvd - LastByteRead \leq RcvBuffer$$

We define 

$$rwnd = RcvBuffer - (LastByteRcvd - LastByteRead)$$

Host B will include $rwnd$ in the ACK segment. Host A need to record $LastByteSent$ and $LastByteAcked$, and make sure that

$$LastByteSent - LastByteAcked \leq rwnd$$

### Technical Problem

If the $rwnd$ is currently $0$, the receiver informs the sender to not send more data. However, after receiver clears the buffer, receiver never have a chance to send ACK to sender because no data is received. And **sender will never send more data**.

To solve this problem, the TCP specification requires host A to **continue to send segments with one data byte**. These segments will be acknowledged by the receiver, and the problem is solved.

# Connection Management

This section talks about how TCP connection is established and torn down.

## Establishing Connection

The TCP connection is established following the steps:

1. The client-side TCP send a special segment which has the **SYN** bit set to $1$. Also, the client randomly chooses an initial sequence number $client\_isn$ and put this in the **sequence number** field.
> If the port is not accepting connections, a special reset segment (with RST flag equals 1) is sent by host.
2. The server host receives the segment, and sends a connection-granted segment with no application-layer data. This segment is also called the **SYNACK segment**.
	- The **SYN** bit of the connection-granted segment is set to $1$.
	- The **acknowledgment** field of the connection-granted segment is set to $client\_isn + 1$.
	- The server chooses its own initial sequence number and puts it in the **sequence number** field of connection-granted segment.
3. Receiving the SYNACK segment, the client allocates buffers and variables for the connection.

> SYN stands for "synchronize sequence number".

Because three packets are sent during the connection process, this procedure is often referred to as a **three-way handshake**.

![[Pasted image 20221115172939.png]]

## Closing the Connection

1. The application process issues a close command. The TCP client send a special packet to server which has the **FIN** bit set to $1$.
2. The server sends an ACK in return.
3. The server then sends its own shutdown segment with the **FIN** bit set to $1$.
4. The client acknowledges the shutdown segment.

![[Pasted image 20221115173434.png]]

## States

During the life of a TCP connection, the TCP protocol running in each host makes transitions through various **TCP states**.

The figure below illustrates a typical sequence of TCP states that are visited by the client TCP.

![[Pasted image 20221115174744.png]]

The figure below illustrates the series of states typically visited by the server-side TCP.

![[Pasted image 20221115174842.png]]

# Congestion Control

## Costs of Congestion

If congestion control is not performed, there are some disadvantage listed below:

1. The sender must perform retransmissions in order to compensate for dropped (lost) packets due to buffer overflow.
2. Uneeded retransmissions by the sender in the face of large delays may cause a router to use its link bandwidth to forward unneeded copies of a packet.
3. When a packet is dropped along a path, the transmission capacity that was used at each of the upstream links to forward that packet to the point at which it is dropped ends up having been wasted.

## Approaches

At highest level, we may classify congestion-control approaches to the two types below:

1. End-to-end congestion control: The [[Networks]] layer provides no explicit support to the [[Transport]] layer for congestion-control purposes.
2. Network-assisted congestion control: Routers provide explicit feedback to the sender and receiver regarding the congestion state of the network.

### Classic TCP Congestion Control

TCP defines these guiding principles to provide congestion control:

- A lost segment implies congestion, and hence, the TCP sender's rate should be decreased when a segment is lost.
- An acknowledged segment indicates that the network is delivering the sender's segments to the receiver, and hence, the sender's rate can be increased when an ACK arrives for a previously unacknowledged segment.
- By using ACKs, we can probe the bandwidth.

More specifically, the details of the **TCP congestion-control algorithm** contains three major components:

1. **Slow Start**: The value of $cwnd$ (congestion window) begins at 1 MSS, and plus 1 for every ACKed segment. If $cwnd \geq ssthresh$ where $ssthresh$ is a variable meaning "slow start threshold", it enters **congestion avoidance** state.
![[Pasted image 20221120102759.png|400]]
2. **Congestion Avoidance**: Instead of exponential growth in **slow start**, we increase $cwnd$ by just a single MSS every RTT. Thus the growth of $cwnd$ is linear growth. If received three duplicate ACKs, it enters **fast recovery** state.
3. **Fast Recovery**: The value of $cwnd$ is increased by 1 MSS for every duplicate ACK received for the missing segment that caused TCP to enter the fast-recovery state. Fast recovery is a recommended, but not required component of TCP.

The above three states can be illustrated by the state diagram below.

![[Pasted image 20221120105026.png]]

### AIMD (TCP Reno)

Viewing the diagram, we observed that the TCP congestion control consists of 

1. linear (additive) increase in $cwnd$ of 1 MSS per RTT and then 
2. a halving (multiplicative decrease) of $cwnd$ on a triple duplicate-ACK event.

![[Pasted image 20221120110040.png]]

For this reason, TCP congestion control is ofen referred to as an **additive-increase, multiplicative-decrease (AIMD)** form of congestion control.

The average throughput of a TCP reno connection is

$$\text{average throughput of a connection} = \frac{0.75 \cdot W}{RTT}$$

### TCP Cubic

Cutting the sending rate in half may be over cautious. 

If the state of the congested link hasn't changed much, then perhaps it's better to more quickly ramp up the sending rate and then probe cautiously for bandwidth.

![[Pasted image 20221120110549.png|500]]

TCP cubic differs only slightly from the TCP in [[#AIMD (TCP Reno)]]. It only changes the congestion avoidance phase as follows:

1. Let $W_{\rm max}$ be the $cwnd$ when loss was last detected. And $K$ is the estimated time when $cwnd$ will reach $W_{\max}$ again.
2. Cubic increases the $cwnd$ as a function of *cube* of the distance between current time $t$ and $K$. 
This means that cubic quickly ramps up the sending rate to get close to the pre-loss rate $W_{\max}$, and probes cautiously for bandwidth as it approaches $W_{\max}$.
3. When $t$ exceeds $K$ and no packet loss occurs, $cwnd$ first has small increases, and then increase rapidly.

### Network Assisted Congestion-Control



---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.