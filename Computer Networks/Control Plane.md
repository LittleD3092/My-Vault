Tag: #computer-networks 
Previous: [[Networks]]
Link: 

---

[TOC]

---

For computing the forwarding and flow tables, we have two possible approaches:

- *Per-router control*: The routing algorithm runs in each and every router. They communicate with each other to compute the values for its forwarding table.
	- ![[Pasted image 20221224163826.png]]
	- [[OSPF]]
	- [[BGP]]
- *Logically centralized control*: A logically centralized controller computes and distributes the forwarding tables to be used by each and every router.
	- ![[Pasted image 20221224164121.png]]

# Routing Algorithms

To determine good paths, routing algorithms are needed.

- A weighted, undirected [[Graph]] is used to represent the routers and links.
- Edges $E$ is the set of all links.
	- An edge with end points $x$ and $y$ is represented by $(x, y)$.
	- Node $y$ is said to be a **neighbor** of $x$ if $(x, y)$ belongs to $E$.
	- The cost of the edge is $c(x, y)$.
	- A path is a sequence of nodes $(x_1, x_2, \dots, x_p)$.
	- The cost of a path is $c(x_1, x_2) + c(x_2, x_3) + \dots + c(x_{p - 1}, x_p)$.
- We want to find the **least-cost path**.

Based on the information required to use the algorithm, there are two types:

- **Centralized routing algorithm**: Requires complete, global knowledge about the network.
- **Decentralized routing algorithm**: 

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.