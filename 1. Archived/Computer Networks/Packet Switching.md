標籤: #computer-networks #list 

---

[TOC]

---

- To send a message from a source end system to a destination end system, the source breaks long messages into smaller chunks of data known as ==packets==.
- Between source and destination, each packet travels through communication links and ==packet switches==. There are two predominant types of packet switches:
	- ==routers==
	- ==link-layer switches==

# Store-and-Forward Transmission

Store-and foward transmission means that the packet switch must receive the entire packet before it can begin to transmit the first bit of the packet on to the outbound link.

Consider the following scenario, which the packet has $L$ bits, and each link has transmit rate of $R$.

![[Pasted image 20221024113530.png|500]]

For the first packet to transmit to the router, it takes $\frac L R$ time. At time $2\frac L R$, the first packet is sent from the router to the destination, also the second packet is sent to the router. Therefore:

$$d = 2\frac L R \qquad \text{for two links, one packet.}$$

And the second packet will be sent within:

$$d = 3\frac{L}{R} \qquad \text{for two links, two packets.}$$

Applying the above concept, we can see that:

$$d_{\text{end-to-end}} = N\frac LR \qquad \text{for {\it N } links, one packet.}$$

For $P$ packets sent over a series of $N$ links, we can see that:

$$\underline{d_{\text{end-to-end}} = (N + P - 1)\frac L R}_\#$$

Since the first packet takes $NL / R$ time, and each packet after it takes another $L / R$ time.

# Queuing Delays and Packet Loss

> To calculate delays, see [[Delay]].

![[Pasted image 20221024115228.png]]

Each packet switch has multiple links attached to it. For each attached link, the packet switch has an ==output buffer== (==output queue==). If multiple packets are needed to be sent through a link, they goes into output buffer, and then be sent one by one.]

Because the packet cannot be sent immediately due to queuing delay, in addition to [[#Store-and-Forward Transmission]] delay, there is also ==queuing delays==.

If the buffer space is completly full but more packets are coming in, ==packet loss== will occur.

# Forwarding Tables and Routing Protocols

In the Internet, every end system has an address called an IP address. As with postal addresses, this address has a hierarchical structure. Each router has a ==forwarding table== that maps destination addresses to that router's outbound links.

The Internet has a number of special ==routing protocols== that are used to automatically set the forwarding tables.

# Delay

![[Delay]]

# Throughput

![[Throughput]]

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.