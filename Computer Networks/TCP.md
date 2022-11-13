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

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.