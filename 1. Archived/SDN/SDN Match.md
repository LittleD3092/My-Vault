Tag: #SDN #computer-networks 
Previous: [[SDN]]
Link: 

[TOC]

---

- OpenFlow 1.0 allows for a match to be made on selected fields from *three* layers.
	- Link layer
	- Network layer
	- Transport layer
	- ![[Pasted image 20221218134009.png]]
- OpenFlow-enabled device can perform as a router ([[Networks]] Layer) and as a switch (Link layer).
- Flow table entries may have wild cards.
	- For example, `128.119.*.*` will match the corresponding address field of any datagram that has `128.119`.
	- If a packet matches multiple entries, the highest priority entry will be used.

---

# Reference

- Kurose, James F., and Keith W. Ross. Computer Networking: A Top-Down Approach. Eighth Edition. Pearson, n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.