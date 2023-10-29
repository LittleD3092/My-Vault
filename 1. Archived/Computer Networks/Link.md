Tag: #computer-networks 
Previous: [[Computer Networks Layers]]
Link: 

---

[TOC]

---

# Introduction

## Terminology

- **Node**: Any device that runs a link-layer protocol.
- **Links**: The channels that connect adjacent nodes.
- **Link-layer frame**: The encapsulated **datagram**.

## Services

- *Framing*: Encapsulate the datagram into a frame.
- *Link access*: MAC (medium access control) protocol specifies the rules by which a frame is transmitted onto the link.
- *Reliable delivery*: Guarantees to move datagram without error.
	- Some low error links like fiber often does not provide reliable delivery.
	- Wireless link need this service.
- [[#Error Detection and Correction]]: Find bit errors and correct them.

## Implementation

![[Pasted image 20221225150520.png]]

- The link layer is implemented on a chip called **network adapter**, also known as a **network interface controller (NIC)**.

# Error Detection and Correction

![[Pasted image 20221225152105.png]]

- The receiver can sometimes, *but not always* detect the bit errors.
	- There may be **undetected bit errors**.
- The ability of the receiver to both detect and correct errors is known as **forward error correction (FEC)**.

## Parity Checks

- The simplest form of error detection is a single **parity bit**.
- Choose the parity bit value that the number of total 1s is even.

![[Pasted image 20221225152710.png]]

The above is not good enough. We have a better version, **two-dimensional parity**:

![[Pasted image 20221225153248.png]]

- Each column and row must have even numbers of 1s.
- Can detect and correct single error.
- Can also detect two errors (but *not correct*).

## Checksumming Methods

- **Internet checksum** is based on this approach.
- Steps:
	1. The data is treated as 16-bit integers, and summed.
	2. The 1s complement of the sum is stored.
	3. While checking, the 1s complement and the 16-bit integers should sum up to `0b11111111 11111111`.

## Cyclic Redundancy Check (CRC)

- Also known as **polynomial codes**.

![[Pasted image 20221225155606.png]]

- Assume the sender and receiver agree on an $r + 1$ bit pattern, **generator** $G$.
	- There are standards for 8-, 12-, 16-, and 32-bit generators.
	- $G_{\text{CRC-32}}=100000100110000010001110110110111$
- CRC bits $R$ are appended to the data to satisfy the following condition:
$$D\cdot 2^r {\ \rm XOR\ } R = n G$$

> The above formula means that "the $d+r$ bits are divisible by $G$".

- The receiver divides the $d + r$ bits by $G$. If the remainder is nonzero, there is an error.

---

- The $R$ is determined by the following formula:

$$R = \text{remainder } \frac{D \cdot 2^r}{G}$$

- An example:

![[Pasted image 20221225160809.png]]

# Multiple Access Problem

- **Multiple access problem**: How to coordinate the access of multiple sending and receiving nodes to a shared broadcast channel?
	- The transmitted frame may **collide** at all of the receivers.
- **Multiple access protocols**: The protocols for this problem.
	- Categories:
		- [[#Channel Partitioning Protocols]]
		- [[#Random Access Protocols]]
		- [[#Taking-Turns Protocols]]

## Channel Partitioning Protocols

> Recall that we have two partitioning techniques: [[Circuit Switching#Time-Division Multiplexing (TDM)|TDM]] and [[Circuit Switching#Frequency-Division Multiplexing (FDM)|FDM]].

- A third protocol is **code division multiple access (CDMA)**.
	- CDMA assign different *code* to each node.
	- Each node uses its code to encode the data bits it sends.
	- Nodes can *simultaneously* send frames.

## Random Access Protocols

- A transmitting node always transmits at the full rate of the channel $R$.
- When a node experiences a collision, *it waits a random delay before retransmitting the frame*.
- Few most commonly used:
	- [[#Slotted ALOHA]]
	- [[#ALOHA]]
	- [[#Carrier Sense Multiple Access (CSMA)]]
	- [[#Carrier Sense Multiple Access with Collision Detection (CSMA/CD)]]

### Slotted ALOHA

![[Pasted image 20221225173658.png]]

- Operation:
	- Time is divided into slots.
	- Nodes send its frame in one slot.
	- If there is a collision, the node retransmits its frame with probability $p$ until the frame is transmitted without a collision.
	- At each slot, the node has probability $p$ of sending, and probability $1 - p$ to skip this slot.
- Advantage:
	- Allows a node to transmit at the full rate $R$ when it is the only node.
	- Decentralized.
- How efficient:
	- **Successful slot**: The slot which only one node transmits.
	- **Efficiency**: The long-run fraction of successful slots when there are a large number of active nodes.

The possibility of a successful slot is:

$$Np(1 - p)^{N - 1}$$

The maximum efficiency is $0.37$.

### ALOHA

- [[#Slotted ALOHA]], but slots are not required.
- Operation:
	- If collision happens, the node wait for a frame transmission time.
- How efficient:
	- The probability of a successful transmission is $$p(1 - p)^{2(N - 1)}$$
	- The efficiency is $$\frac{1}{2e}$$

### Carrier Sense Multiple Access (CSMA)

- Operation:
	- *Listen before speaking*: **carrier sensing**.
- Although the protocol has **carrier sensing**, collision can still occur. 
	- The following figure shows the nodes B and D started transmition at different time.
	- During the start of D's transmission, it does not know B is transmitting.
	- You can see that **channel propagation delay** plays an important role.

![[Pasted image 20221225181528.png]]

### Carrier Sense Multiple Access with Collision Detection (CSMA/CD)

- [[#Carrier Sense Multiple Access (CSMA)|CMSA]], but with collision detection.
	- *If someone else begins talking at the same time, stop talking*: **collision detection**.
- Take the figure above as an example, CSMA/CD will stop B and D from transmitting when they receive each other's frame.
- Operation:
	1. The adapter obtains a datagram from [[Networks]] layer.
	2. If the adapter senses that the channel is idle, it start to transmit. If the channel is busy, it waits until the channel is available.
	3. While transmitting, the adapter monitors other signals.
	4. If the adapter transmits the entire frame, the adapter is finished with the frame. If other signals are detected, it aborts the transmission.
	5. After aborting, the adapter waits a random amount of time. Then go to step 2.
- Delay:
	- How to determine the random delay time?
	- Too long is inefficient, too short makes the nodes collide.
	- **Binary exponential backoff** algorithm solve this.
		- Suppose the transmition of the same frame experienced $n$ collisions.
		- Choose a random value $K$ from $0\sim 2^{n - 1}$.
		- Wait $K\cdot 512\text{ bit}$ times.
		- The maximum $n$ is 10.
- Efficiency: $$\text{Efficiency} = \frac{1}{1 + 5d_{\rm prop} / d_{\rm trans}}$$

## Taking-Turns Protocols

- There are many taking-turns protocols.
- Two of the more important protocols:
	- **Polling protocol**
		- Operation:
			- A master node **polls** each of the nodes in a round-robin fashion.
			- The master tells other nodes it is their turn to transmit.
		- Disadvantage:
			- The time used to notify a node, **polling delay**.
			- Master node cannot fail.
	- **Token-passing protocol**
		- Operation:
			- A **token** is exchanged among the nodes.
			- The order of passing the token is fixed.
			- The node that currently has token can transmit a maximum number of frames.
			- Then the token is passed.
		- Disadvantage:
			- The failure of one node can crash the entire channel.

# Switched Networks

![[Pasted image 20221225194412.png]]

## Addressing

### MAC Addresses

- **Link-layer address**, **physical address**, **LAN address**.
- 6 bytes long, $2^{48}$ possibilities.
- Bind to an adapter.
- Does not change no matter where the adapter goes.
- A **broadcast address**, `FF-FF-FF-FF-FF-FF` is used to broadcast a frame.

### Address Resolution Protocol (ARP)

- Used to translate MAC address and IP address.
- Operation:
	- Each host and router has an **ARP table** that maps IP addresses to MAC addresses.
		- The ARP table has a time-to-live (TTL) value.
	- If the ARP table does not currently have the entry, sender constructs an **ARP packet** and query all other hosts and routers.
	- The hosts or routers that contain the entry responds with another ARP packet.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.