標籤: #computer-networks 

---

[TOC]

---

A high-level view of a generic router architecture is shown in figure below.

![[Pasted image 20221120161636.png]]

Four router components can be identified:

- [[#Input Ports]]
	- Performs physical-layer function of terminating an incoming physical link at the router.
	- Performs link-layer functions that interoperate with incoming link.
	- Performs lookup function and consult the forwarding table.
- [[#Switching Fabric]]
	- Connects the router's input ports to its output ports.
- [[#Output Ports]]
	- Store and transmit the packets on the outgoing link.
	- When a link is bidirectional (carries traffic in both directions), an output port is paired with an input port.
- *Routing processor*
	- Performs [[Control Plane]] functions.
	- The routing processor is responsible for communicating with the remote controller to update the forwarding table.

> Input ports, switching fabric and output ports are almost always implemented in hardware.

# Components

## Input Ports

A detailed view of input processing shown in the figure below.

![[Pasted image 20221120163628.png]]

The forwarding table includes **prefixes** and its corresponding **link interface**. If a packet's destination address matches the prefix, it is sent via the corresponding link interface.

Below is an example of forwarding table:

$$
\begin{array}{lr}
	\textbf{Prefix} & \textbf{Link Interface} \\
	11001000\ \ 00010111\ \ 00010 & 0 \\
	11001000\ \ 00010111\ \ 00011000 & 1\\
	11001000\ \ 00010111\ \ 00011 & 2 \\
	\text{Otherwise} & 3
\end{array}
$$

> You may notice that an address may match multiple prefixes. In this case, the router uses the **longest prefix matching rule**, which finds the longest matching entry in the table and forwards the packet to the link interface.

## Switching Fabric

Switching can be accomplished in a number of ways:

- *Switching via memory*
	- The simplest, earliest routers were traditinoal computers.
	- The input and output ports are done under direct control of CPU.
	- Note that different packets cannot be forwarded at the same time since only one memory read/write can done at a time.
- *Switching via a bus*
	- A label is added to the packet, and all output will receive this packet. But, only the output port that matches the label will keep the packet.
	- Only one packet can cross the bus at the same time.
- *Switching via an interconnection network*
	- Uses a crossbar switch. Consists of $2N$ buses for $N$ input and $N$ output. 
	- The switch controller closes the corresponding intersection and open other intersections when a packet enters.
	- This is **non-blocking**, and multiple packets can be forwarded at the same time.
	- However, if two packets from two different input has the same output port, then one will have to wait.

![[Pasted image 20221120171155.png]]

## Output Ports

Output port processing is shown in the figure below.

![[Pasted image 20221120171404.png]]

- The output queueing is where **packet loss** will occur.

# Queuing

## Input Queuing

If the switch fabric is not fast enough to transfer all arriving packets through the fabric without delay, packet queuing will occur at input queue.

![[Pasted image 20221204145849.png]]

Note that the light blue packet is behind the dark blue packet in the figure above. The light blue packet must wait for dark blue packet to be sent, although the queue for middle output is empty. This is called **head-of-the-line (HOL) blocking**.

> **Head-of-the-line (HOL) blocking**: A queued packet in an input queue must wait for transfer through the fabric (even though its output port is free) because it is blocked by another packet at the head of the line.

## Output Queuing

If several input ports are destined to the same output port, output queuing can occur.

![[Pasted image 20221204151034.png]]

- When there is not enough memory to buffer an incoming packet, a decision must be made.
	- Drop the arriving packet. It is known as **drop-tail** policy.
	- Remove one or more already-queued packets to make room for the newly arrived packet.
- A number of packet-dropping and packet-marking policies (**active queue management (AQM)** algorithms) have been proposed and analyzed.
	- Most widely studied and implemented: **Random Early Detection (RED)** algorithm.
	- PIE (the Proportional Integral controller Enhanced).
	- CoDel.

# How Much Buffering?

- The rule for buffer sizing was that the amout of buffering $B$ should be equal to an average round-trip time $RTT$ times the link capacity $C$.
$$B = RTT \cdot C$$
For example, a 10-Gbps link with an RTT of 250 msec would need 2.5 Gbits of buffering.
- More recent theoretical and experimental research shows that when a large number of *independent* [[TCP]] flows $N$ pass through a link, 
$$B = \frac{RTT \cdot C}{\sqrt{N}}$$
- Actually, *more buffering is not better*.
	- More buffering absorbs short-term fluctuations in traffic, but leads to *longer delays*.
	- This scenario is known as **bufferbloat**.

# Packet Scheduling

## First-in-First-Out (FIFO)

Selects packets for link transmission in the same order in which they arrived at the output link queue.

![[Pasted image 20221204153744.png]]

![[Pasted image 20221204153849.png]]

## Priority Queuing

## Round Robin and Weighted Fair Queuing (WFQ)

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.