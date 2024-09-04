Tag: #SDN #computer-networks 
Previous: [[SDN]]
Link: 

[TOC]

---

- Each flow table entry has a list of zero or more actions.
- If there are multiple actions, they are performed in the order specified in the list.

Among the most important possible actions are:

- *Forwarding*.
	- Forward a packet to a particular port.
	- Broadcast a packet over all ports.
	- Multicast a packet over a selected set of ports.
- *Dropping*.
- *Modify-field*.
	- The values in 10 packet-header can be modified before forwarding.

---

# Reference

- Kurose, James F., and Keith W. Ross. Computer Networking: A Top-Down Approach. Eighth Edition. Pearson, n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.