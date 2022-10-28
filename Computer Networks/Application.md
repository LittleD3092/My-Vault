標籤: #computer-networks 

---

[TOC]

---

![[Pasted image 20221029010856.png]]

- ==Application architecture== is designed by the application developer and dictates how the application is structured over the various end systems.
	- In choosing the application architecture, a developer will likely draw on one of the two predominant architectural paradigms.
	![[Pasted image 20221029011612.png]]
- ==Client-server architecture==
	- There is an always-on host, called the ==server==.
	- Servers service requests from many other hosts, called ==clients==.
- ==P2P architecture==
	- The application exploits direct communication between pairs of intermittently connected hosts, called ==peers==.
	- The peers communicate without passing through a dedicated server.
	- P2P architecture has ==self-scalability==.

# Processes Communicating

- ==Processes==
	- The thing that communicates.
	- Can be thought of as a program.
- ==Messages==
	- Processes on different end systems communicate with each other by exchanging messages across the computer network.

## Client and Server Processes

- We typically label one of the two processes as the ==client== and the other process as the ==server==.
	- Note that a process can be both a client and a server at the same time.

> We define the client and server processes as follows:
> *In the context of a communication session between a pair of processes, the process that initiates the communication (that is, initially contacts the other process at the beginning of the session) is labeled as ==client==. The process that waits to be contacted to begin the session is the ==server==.*

## Interface Between Process and Network

- ==Socket==
	- A process send into and receive messages through a software interface called a socket.
	- Socket is also referred to as the ==Application Programming Interface (API)== between the application and the network.
	![[Pasted image 20221029014710.png]]
	- The only control that the application developer has on the transport-layer side is
		1. the choice of transport protocol
		2. perhaps the ability to fix a few transport-layer parameters such as miximum buffer and maximum segment sizes.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition.

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.