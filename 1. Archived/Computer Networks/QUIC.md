標籤: #computer-networks 

---

[TOC]

---

QUIC (Quick UDP Internet Connections) protocol is a new application-layer protocol designed from the ground up to improve the performance of transport-layer services for secure HTTP.

Some QUIC's major features include:

- **Connection-Oriented and Secure**: All packets are encrypted, and the authentication is combined with the handshake. Therefore provide a faster protocol.
- **Streams**: Allow multiple application-level "streams" to use a single QUIC connection. Once a connection is established, new streams can be quickly added.
- **Reliable, TCP-friendly congestion-controlled data transfer**: Provides reliable data transfer to each QUIC stream **seperately**. 
	- If using HTTP 1.1 and the segment is lost, the remaining segments cannot be delivered until the lost segments are received.

---

參考資料:

Computer Networks, A Top-Down Approach, 8th edition

---

link:

[[HTTP]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.