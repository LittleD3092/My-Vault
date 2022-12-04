標籤: #computer-networks 

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

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.