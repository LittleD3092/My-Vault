標籤: #computer-networks 
Link: [[Network Address Translation]]

---

[TOC]

---

# Datagram Format

The key fields in the IPv4 datagram are the following:

- *Version number*.
	- 4 bits.
	- Specify IP [[Protocols|protocol]] version.
- *Header length*.
	- Because an IPv4 datagram can contain a variable number of options, this field is needed.
	- 4 bits.
	- Determine where in the IP datagram the payload actually begins.
	- Most IP datagram do not contain options, so the typical IP datagram has a 20-byte header.
- *Type of service*.
	- Allow different types of IP datagramsto be distinguished.
	- For example, it might be useful to distinguish real-time datagrams from non-real-time ones.
- *Datagram length*.
	- The total length of the IP datagram.
- *Identifier, flags, fragmentation offset*.
	- The three fields help with IP fragmentation.
	- Allow a large IP datagram to be broken into several smaller IP datagrams.
- *Time-to-live*.
	- Known as TTL.
	- Ensure that datagrams do not circulate forever.
	- This field is decremented by one each time the datagram is processed by a router.
	- If reaches 0, a router must drop the datagram.
- *Protocol*.
	- Used only when datagram reaches its final destination.
	- The value indicates the [[Transport]] layer protocol.
- *Header checksum*.
	- Used to detect bit errors. 
	- Use similar method in [[UDP#Checksum]].
	- A router computes the header checksum.
	- Note that it checks only the header, not including the payload.
	- Note that checksum must be recomputed and stored again at each router, since TTL field and possibly other fields might change.
- *Source and destination IP addresses*.
- *Options*
	- Allow an IP header to be extended.
- *Data (payload)*
	- Contains [[Transport]] layer segment to be delivered to the destination.

# Addressing

- The boundary between the host and the physical link is called an **interface**.
- Each IP address is 32 bits long.
- The addresses are written in **dotted-decimal notation**.
	- For example, `193.32.216.9`.

![[Pasted image 20221205132353.png]]

- The network interconnecting three host interfaces and one router interface forms a **subnet**.
	- In the above example, the address of the subnet is `223.1.1.0/24`.
	- `/24` is the **subnet mask**, indicating that the leftmost 24 bits define the subnet addresses.
	- The *link between the routers* is also a subnet.
	- ![[Pasted image 20221205133121.png|500]]

## Addressing Strategy

- The internet assignment strategy is **Classless Interdomain Routing (CIDR)**.
	- An address of a subnet is in the form `a.b.c.d/x`.
	- The most significant `x` bits of an address are called **prefix**.
	- The ability to use a single prefix to advertise multiple networks is often referred to as **address aggregation**. (or **route aggregation** or **route summarization**).
		- ![[Pasted image 20221205135039.png]]
	- When a host sends a datagram with destination address `255.255.255.255` (the **IP broadcast address**), the message is delivered to all hosts on the same subnet.
- Before CIDR, an addressing scheme known as **classful addressing** is used.
	- The network portions of an IP address were constrained to be *8, 16 or 24 bits* in length.
	- 8-, 16- and 24-bit subnet addresses were known as *class A, B, and C* networks.
	- A class B address supports too many hosts (65534 hosts) and class A address supports too few (254 hosts). This cause *poor utilization* of the assigned address space.

## Obtaining a Host Address: DHCP

[[DHCP]]

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.