Tag: #network-science 
Previous: [[Centrality]]
Link: 

[TOC]

---

Katz centrality is similar to [[Eigenvector Centrality]], but instead of considering only the shortest path, it measures influence by taking into account the total number of walks between two nodes.

It is defined as:

$$C_{\rm Katz}(i) = \sum_{k = 1}^{\infty}
\sum_{j = 1}^{n} \alpha^k(A^k)_{ji}$$

- $C_{\rm Katz}(i)$: Katz centrality of node $i$.
- $\alpha$: Attenuation factor, a value between $0$ and $1$.

---

# Reference

Network Science Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.