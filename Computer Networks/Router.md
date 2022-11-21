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

# Input Ports

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

# Switching Fabric

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

# Output Ports

Output port processing is shown in the figure below.

![[Pasted image 20221120171404.png]]

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.