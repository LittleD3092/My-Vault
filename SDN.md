Tag: #computer-networks 
Previous: [[Data Plane]]
Link: 

---

[TOC]

---

- SDN stands for software defined network.
- It uses a **flow table** for forwarding.

![[Pasted image 20221217162715.png]]

Each entry in the flow table includes:

- *A set of header field values* to which an incoming packet will be matched.
	- Hardware-based matching is most rapidly performed.
	- A packet that does not match can be dropped or sent to the remote controller for further processing.
	- May be implemented using multiple flow table.
- *A set of counters* that are updated as packets are matched to flow table entries.
	- The counter includes 
		- The number of packets that have been matched by the table entry.
		- The time since the table entry was last updated.
- *A set of actions to be taken* when a packet matches a flow table entry.
	- Example:
		- Forward the packet to a given output port.
		- Drop the packet.
		- Make copies of the packet and sent then to multiple output ports.
		- Rewrite selected header fields.

As we can see, the process contains two steps:

1. [[#Match]]
2. [[#Action]]

# Match

- OpenFlow 1.0 allows for a match to be made on selected fields from *three* layers.
	- Link layer
	- Network layer
	- Transport layer
	- #TODO Figure 4.29
- OpenFlow-enabled device can perform as a router ([[Networks]] Layer) and as a switch (Link layer).

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.