Tag: #network-science 
Previous: [[Assortative Mixing with Unordered Features]]
Link: 

[TOC]

---

The actual intra-edges of a network can be calculated by the formula below:

$$\sum_{{\rm edge}(i, j)} \delta_{g_ig_j} = \frac 1 2 \sum_{ij}A_{ij}\delta_{g_ig_j}$$

- ${\rm edge}(i, j)$: For each edge and its nodes $ij$.
- $\displaystyle\frac{1}{2}$: On the right side, the $ij$ are calculated twice for each edge, therefore need to be divided by $2$.
- $A_{ij}$: An element in the adjacency matrix.
- $\delta_{g_ig_j}$: [[Kronecker Delta]]

---

# Reference

1. Lou, Yang. “Network Science, Lecture 7: Community Structure.” NYCU ED102[GF], November 7, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.