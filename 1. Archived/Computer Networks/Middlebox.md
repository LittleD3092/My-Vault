Tag: #computer-networks 
Previous: [[Data Plane]]
Link: 

---

[TOC]

---

> RFC3234 define **middleboxes** as:
> *"any intermediary box performing functions apart from normal, standard functions of an IP router on the data path between a source host and destination host"*

We can identify three types of services performed by middleboxes:

1. *[[Network Address Translation|NAT Translation]]*: Rewrite datagram header IP addresses and port numbers.
2. *Security Services*: Firewalls. Some examples:
	- *DPI (Deep Packet Inspection)*: Block traffic based on header-field values or redirect packets for additional processing.
	- *IDS (Intrusion Detection Systems)*: Detect predetermined patterns and filter packets.
	- [[Application]]-level email filters that block emails.
3. *Performance Enhancement*: 
	- Compression.
	- Content caching.
	- Load balancing of service requests.

The approach of using specialized hardware, separate software stacks, and separate management/operation skills (*aka middleboxing*) is known as **network function virtualization**.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.