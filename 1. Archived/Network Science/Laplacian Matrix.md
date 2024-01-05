Tag: #network-science 
Previous: [[Network Science]]
Link: [[Adjacency Matrices]]

[TOC]

---

Laplacian matrix is an adjacency matrix that utilize the main diagonal for storing the degree of each node.

Laplacian matrix can be defined as:

$$L_{ij} = 
\left\{
	\begin{array}{l}
		k_i & \text{if } i = j \\
		-1 & \text{if } i \neq j \text{ and } A_{ij} \neq 0 \\
		0 & \text{otherwise}
	\end{array}
\right.$$

And can be obtained by using degree matrix $\bf D$ and adjacency matrix $\bf A$:

$${\bf L} = {\bf D} - {\bf A}$$

- $\bf L$: Laplacian matrix.
- $\bf D$: Degree matrix.
- $\bf A$: Adjacency matrix.

**Note:** This matrix is only useful in undirected graph.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.