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

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.