Tag: #network-science 
Previous: [[Clustering Coefficient]]
Link: 

[TOC]

---

The local clustering coefficient shows the **connectivity of a node's neighbors**.

It can be defined by:

$$C_i = \frac{2T_i}{k_i(k_i - 1)}$$

- $C_i$: The local clustering coefficient of node $i$.
- $T_i$: The number of links between neighbors of node $i$.
- $k_i$: The degree of node $i$.
- $2T_i$: A link is considered two connections.
- $k_i(k_i - 1)$: Number of pairs of neighbors.

For example the local clustering coefficient of the network below:

![[Pasted image 20231020153304.png|200]]

| $i$ | $T_i$ | $k_i$ | $C_i$ |
| --- | ----- | ----- | ----- |
| $0$ | $1$   | $2$   | $1$   |
| $1$ | $1$   | $3$   | $1/3$ |
| $2$ | $2$   | $4$   | $1/3$ |
| $3$ | $2$   | $3$   | $2/3$ |
| $4$ | $5$   | $5$   | $1/2$ |
| $5$ | $4$   | $5$   | $2/5$ |
| $6$ | $3$   | $3$   | $1$   |
| $7$ | $3$   | $3$   | $1$   | 

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.