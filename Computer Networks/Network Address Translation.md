標籤: #computer-networks 

---

[TOC]

---

- Also called **NAT**.

# Why NAT

![[Pasted image 20221217140456.png]]

- The four interfaces in the home network have the same subnet address `10.0.0.0/24`.
	- The address space `10.0.0.0/8` is reserved for a **private network** or **realm with private addresses**.
	- This means the addresses can only have meaning within the given home network.
- The NAT handles the translation between home network and global network.

# How it works

- The NAT-enabled router behaves as a *single* device to the outside world with a *single* IP address.
- The NAT-enabled router get its single IP address through ISP's [[DHCP]] server.
- The router act as a [[DHCP]] server to provide addresses to computers in the network.

## NAT Translation Table

- The router uses a NAT translation table to handle ip translation.
- Consider a host `10.0.0.1:3345` requests a Web page on `128.119.40.186:80`:
	1. The router receives the datagram of requesting a Web page.
	2. The NAT router writes a new entry in translation table `138.76.29.7:5001` for `10.0.0.1:3345`.
	3. The NAT router sends the Web page request on behalf of `138.76.29.7:5001`.
	4. The Web server responds with destination `138.76.29.7:5001`.
	5. The NAT router receives the respond, and translate the destination IP address to `10.0.0.1:3345` using the translation table.
	6. The respond is sent to the host `10.0.0.1:3345`.

# Cons

- Port numbers are meant to be used for addressing *processes*, not *hosts*.
	- A scenario:
		- If a host under the home network runs a server, it wait for incoming requests at well-known port numbers.
		- A client outside the network may never reach the server using the well-known port numbers!
	- It **violates** that hosts should be taking directly with each other.
	- Solution: **NAT traversal** tools.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:

[[Networks]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.