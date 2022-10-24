標籤: #computer-networks #list 

---

[TOC]

---

![[internet components - computer networks basics.jpg]]

The internet is consisted with four things:

- Devices ([[Edges]])
	- They are called ==hosts== or ==end systems==.
	- This may be personal computer, may be a server.
- Packet switches
	- Consisted of ==routers== and ==link-layer switches==.
	- Act as a cross section, connect communication links together.
- [[Communication Links]]
	- A line of communication, can be made of fiber, copper, radio or satellite.
	- The form of communication links determUntitledines the ==transmission rate==.
- [[Networks]]
	- A collection of devices, routers and links managed by an organization.
	- eg. A home network, data center network, Taiwan Acadamic Network.

More concepts:

- The internet is basically a network of smaller networks.
- The sequence of communication links and packet switches traversed py a packet is known as a ==route== or ==path==.
- End systems access the Internet through ==Internet Service Providers==, including:
	- residensial ISPs, local cable or telephone companies
	- corporate ISPs
	- university ISPs
	- public places WiFi access
	- cellular data ISPs.
	- The ISPs is itself a network. These lower tier ISPs are connected by higher tier ISPs, forming a bigger network.

# Protocals

![[Protocals]]

# Internet Standards

It is important that everyone agree on what each and every protocol does, so that people can create systems and products that interoperate. 

==Internet standards== are developed by the Internet Engineering Task Force (IETF). The IETF standards documents are called ==requests for commments (RFSs)==.

# A Service Description

Aside the nuts-and-bolts description, we can describe the Internet from an different angle. The Internet is also an infrastructure that provides services to applications.

- The applications are said to be ==disributed applications==, since they involve multiple end systems that exchange data with each other.
- End systems provide a ==socket interface== for these applications to access the Internet.
	- The socket interface is a set of rules that the sending program must follow.

---

參考資料:

Intro. to Computer Networks class
Computer Networking, A Top-Down Approach, 8th edition.

---

link:

