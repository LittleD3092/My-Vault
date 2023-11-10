Tag: #network-science 
Previous: [[Assortative Mixing]]
Link: 

[TOC]

---

The average ordered features $x_i$ over edges is given by: (<u>1</u>)

$$
\mu = \frac{\sum_{ij} A_{ij} x_{i}}{\sum_{ij} A_{ij}} = \frac{1}{2m} \sum_i k_i x_i
$$

And the covariance (the relations) of $x_i$ and $x_j$ over edges:

$$\begin{array}{l}
	\text{cov}(x_i, x_j) & = &
	\displaystyle
	\frac{\sum_{ij}A_{ij}(x_i - \mu)(x_j - \mu)}{\sum_{ij}A_{ij}} \\
	& = & \displaystyle
	\frac{1}{2m} \sum_{ij}A_{ij}(x_i x_j - \mu x_i - \mu x_j + \mu^2) \\
	& = & \displaystyle
	\frac{1}{2m} \sum_{ij} A_{ij}x_ix_j - \mu^2 \\
	& = & \displaystyle
	\frac{1}{2m} \sum_{ij} A_{ij}x_i x_j - \frac{1}{(2m)^2} \sum_{ij} k_i k_j x_i x_j \\
	& = & \displaystyle
	\frac{1}{2m} \sum_{ij} \left(
		A_{ij} - \frac{k_i k_j}{2m}
	\right) x_i x_j
\end{array}$$

- ${\rm cov}(x_i, x_j) > 0$: $x_i$ and $x_j$ at the end of edges are close.
- ${\rm cov}(x_i, x_j) < 0$: $x_i$ and $x_j$ at the end of edges are not close.

Related topics:

- [[Assortativity Coefficient for Ordered Features]]

---

# Reference

1. Lou, Yang. “Network Science, Lecture 7: Community Structure.” NYCU ED102[GF], November 7, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.