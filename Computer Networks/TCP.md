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
	- *RST*, *SYN*, *FIN*: Used for connection setup and teardown.
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

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.