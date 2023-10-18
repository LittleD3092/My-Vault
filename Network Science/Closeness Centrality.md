Tag: #network-science 
Previous: [[Centrality]]
Link: 

[TOC]

---

Closeness centrality measures the average shortest path from a node to other nodes.

$$
C(u) = \frac{n}{\sum_v d(u, v)}
$$
or
$$C(u) = \frac{n - 1}{\sum_v d(u, v)}$$

- $C(u)$: Closeness centrality of node $u$.
- $n$: Number of total nodes.
- $d(u, v)$: The shortest path from node $u$ to node $v$.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.