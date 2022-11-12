標籤: #computer-networks 

---

[TOC]

---

- Transport-layer [[Protocals]] provides for ==logical communication== between different hosts.
	- *Logical communication*: From an application's percpective, it is as if the hosts were directly connected.
- Implemented in the end systems but not in network routers.
- Converts the sending message into transport-layer ==segments==.

# Transport vs Network Layers

| Transport Layer                                    | [[Networks]] Layer                              |
| -------------------------------------------------- | ----------------------------------------------- |
| Provides logical communication between *processes*. | Provides logical communication between *hosts*. |

# Multiplexing and Demultiplexing

A process can have one or more sockets. The transport layer in the receiving host deliver data to an intermediary socket.

The job of delivering the data in a transport-layer segment to the correct socket is called ==demultiplexing==.

The job of gathering, encapsulating, and passing the data segments to the [[Networks]] layer is called ==multiplexing==.

## Ports

To do the multiplexing and demultiplexing, 

1. the sockets must have unique identifier, and 
2. each segment have special fields that indicate the socket to which the segment is to be delivered.

The unique identifiers are called ports.

The special fields in the segment are ==source port number field== and ==destination port number field==.

![[Pasted image 20221112161411.png]]

The port numbers ranging from 0 to 1023 are called ==well-known port numbers== and are restricted, which means that they are reserved for use by well-known application protocols such as

- HTTP uses port 80
- FTP uses port 21

# Some Transport Protocols

- [[TCP]]
- [[UDP]]

## Applications and Their Transport Protocols

| Application                   | Application-Layer Protocol | Underlying Transport Protocol    |
| ----------------------------- | -------------------------- | -------------------------------- |
| e-mail                        | SMTP                       | TCP                              |
| Remote terminal access        | Telnet                     | TCP                              |
| Secure remote terminal access | SSH                        | TCP                              |
| Web                           | HTTP, HTTP/3               | TCP (for HTTP), UDP (for HTTP/3) |
| File transfer                 | FTP                        | TCP                              |
| Remote file server            | NFS                        | Typicaly UDP                     |
| Streaming multimedia          | DASH                       | TCP                              |
| Internet telephony            | typically proprietary      | UDP or TCP                       |
| Network management            | SNMP                       | Typically UDP                    |
| Name translation              | DNS                        | Typically UDP                    | 

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition.

---

link:

[[Networks]]
[[UDP]]
[[TCP]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.