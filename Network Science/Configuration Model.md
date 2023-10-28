Tag: #network-science 
Previous: [[Small-world Network]]
Link: 

[TOC]

---

To construct a configuration model, we start with multiple nodes each with a desired "degree".

![[Pasted image 20231028142034.png|200]]

Then we connect the half-edges randomly. For node $i$ and node $j$ to **connect**, the **probability**:

$$p_{ij} = \frac{k_ik_j}{2m - 1}$$

Configuration model is similar to the [[Random Graph|random graph]] $G(n, m)$ and $G(n, p)$, but with fixed degree for each node.

---

# Reference

- Lou, Yang. “Network Science, Lecture 5: Small-World Models.” NYCU ED102[GF], October 17, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.