Tag: #network-science 
Previous: [[Centrality]]
Link: 

[TOC]

---

Betweenness centrality is the number of shortest paths that passes a node.

$$x_i = \sum_{s, t}\frac{n_{s, t}^i}{g_{s, t}}$$

- $x_i$: Betweenness centrality of node $i$.
- $n_{s, t}^i$: Number of shortest paths from node $s$ to node $t$ that passes node $i$.
- $g_{s, t}$: The total number of shortest path from node $s$ to node $t$.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.