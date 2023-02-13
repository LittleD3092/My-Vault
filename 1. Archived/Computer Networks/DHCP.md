標籤: #computer-networks 
Previous: [[IPv4]]
Link:

---

[TOC]

---

- The organization assign individual IP addresses to the host using **Dynamic Host Configuration Protocol (DHCP)**.
	- Allows a host to obtain an IP address automatically.
- Can be configured to give host a static IP address or **temporary IP address**.
- Allow host to learn additional information.
	- Subnet mask.
	- The address of its first-hop router.
	- The address of its local DNS server.
- Is a **plug-and-play** or **zeroconf** protocol.

For a newly arriving host, the DHCP protocol is a four-step process:

1. *DHCP server discovery*.
	- Using a **DHCP discover message**.
	- Using a UDP packet to port 67.
	- Because host does not know the DHCP server address, a destination address of `255.255.255.255` (broadcast address) is used.
	- Because host has not been assigned an address, source IP address `0.0.0.0` is used.
2. *DHCP server offers(s)*.
	- DHCP server responds the DHCP discover message with a **DHCP offer message**.
	- Using the `255.255.255.255` (broadcast address) to respond.
	- Multiple DHCP servers on the same subnet can response.
	- Contains:
		- Transaction ID of the received discover message.
		- The proposed IP address for the client.
		- The network mask.
		- An IP **address lease time**. This is the time for which the IP address will be valid.
3. *DHCP request*.
	- The newly arriving client will choose from among one or more server offers and respond to its selected offer.
	- The message is called **DHCP request message**.
	- Contains configuration parameters.
4. *DHCP ACK*.
	- The server responds to the DHCP request.
	- The message is called **DHCP ACK message**.

![[Pasted image 20221205160554.png]]

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.