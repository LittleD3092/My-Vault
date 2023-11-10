Tag: #network-science 
Previous: [[Assortative Mixing with Ordered Features]]
Link: 

[TOC]

---

The perfect assortative mixing with ordered features has a value:

$$\frac{1}{2m} \sum_{ij} \left(
	k_i \delta_{ij} - \frac{k_i k_j}{2m}
\right)x_i x_j$$

By the above perfect assortative mixing and the previous [[Assortative Mixing with Ordered Features|assortative mixing with ordered features]], we can get a normalized assortative mixing, called **assortativity coefficient**. This value is guaranteed to be $-1 \sim 1$:

$$
\begin{array}{}
	r &=& 
	\displaystyle
	\frac{
		\displaystyle
		\frac{1}{2m}
		\sum_{ij} \left(
			A_{ij} - \frac{k_i k_j}{2m}
		\right) x_i x_j
	}{
		\displaystyle
		\frac{1}{2m}
		\sum_{ij} \left(
			k_i \delta_{ij} - 
			\frac{k_i k_j}{2m}
		\right) x_i x_j
	} \\
	&=& \displaystyle
	\frac{
		\displaystyle
		\sum_{ij}
		\left(
			A_{ij} - \frac{k_i k_j}{2m}
		\right)x_i x_j
	}{
		\displaystyle
		\sum_{ij}
		\left(
			k_i \delta_{ij} - \frac{k_i k_j}{2m}
		\right)x_i x_j
	}
\end{array}
$$

- $r = 0$: $x_i$ at the ends of edges are uncorrelated.
- $r = 1$: The network is perfectly assortative.
- $r = -1$: The network is perfectly disassortative.

---

# Reference

1. Lou, Yang. “Network Science, Lecture 7: Community Structure.” NYCU ED102[GF], November 7, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.