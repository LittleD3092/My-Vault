Tag: #network-science 
Previous: [[Similarity of Node in Network]]
Link: 

[TOC]

---

We know that 

$$\cos\theta = \frac{x \cdot y}{\vert x \vert \vert y\vert}$$

Therefore we write cosine similarity as:

$$
\begin{array}{}
	\delta_{ij} &=& \cos\theta \\
	&=& 
	\displaystyle
	\frac{\sum_{k}A_{ik} A_{kj}}{\sqrt{k_i} \sqrt{k_j}} \\
	&=& \displaystyle
	\frac{n_{ij}}{\sqrt{k_i k_j}}
\end{array}
$$

- $k_i, k_j$: Degree of two nodes.
- $n_{ij}$: The inner product of adjacency matrix.

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.