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
- *flag field*: Contains 6 bits.
	- *ACK*: Indicate that the segment contains an acknowledgment.
	- *RST*, *SYN*, *FIN*: Used for connection setup and teardown.

## Sequence Numbers and Acknowledgement Numbers

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.