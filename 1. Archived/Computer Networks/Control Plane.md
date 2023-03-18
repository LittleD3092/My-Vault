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
	- [[#Link-State (LS) Routing Algorithm]]
- **Decentralized routing algorithm**: The calculation is iterative, the router can first calculate based on closer routers, then further routers.
	- [[#Distance-Vector (DV) Routing Algorithm]]

Based on dynamic or static, we can also classify the algorithms into:

- **Static routing algorithm**: Change very slowly, often as a result of human intervention.
- **Dynamic routing algorithm**: Change the paths as the network traffic loads or topology change.

Based on whether they are load-sensitive or not, we can also classify the algorithms into:

- **Load-sensitive algorithm**: The algorithm tend to choose routes around such a congested link.
	- ARPAnet routing algorithms.
	- There are a number of difficulties.
- **Load-insensitive**: The link's cost does not explicitly reflect its current level of congestion.

## Link-State (LS) Routing Algorithm

- All link costs are known.
- In practice, all nodes broadcast its edges and weights.
	- Accomplished by a **link-state broadcast** algorithm.
- The same as [[Dijkstra Algorithm]].

Given the following graph:

![[Pasted image 20221224223858.png|400]]

The running of the graph is:

| step | u     | v     | w     | x     | y        | z        |
| ---- | ----- | ----- | ----- | ----- | -------- | -------- |
| 0    | ==0== | 2     | 5     | 1     | $\infty$ | $\infty$ |
| 1    | ==0== | 2     | 4     | ==1== | 2        | $\infty$ |
| 2    | ==0== | ==2== | 4     | ==1== | 2        | $\infty$ |
| 3    | ==0== | ==2== | 3     | ==1== | ==2==    | 4        |
| 4    | ==0== | ==2== | ==3== | ==1== | ==2==    | 4        |

The steps are:

1. List the distance. The starting node has a highlighted 0, and its neighbor has distance equal to weight.
2. Highlight the distance that has smallest node, and determine the distance of its neighbors.
3. Go to 2.

It appears that oscillations may happen:

![[Pasted image 20221224230010.png]]

To solve oscillation, the routers can randomize the time it sends out a link advertisement.

## Distance-Vector (DV) Routing Algorithm

- *Iterative*: This process continues on until no more information is exchanged between the nodes.
- *Asynchronous*: Does not require all of the nodes to operate in lockstep with each other.
- *Distributed*: Each node receives some information from one or more of its *directly attached neighbors*.
- Same as [[Bellman-Ford Algorithm]].

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.