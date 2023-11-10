Tag: #network-science 
Previous: [[Assortative Mixing with Unordered Features]]
Link: 

[TOC]

---

The formula of [[Assortative Mixing with Unordered Features|assortative mixing with unordered features]] is often simplified by $B_{ij}$ and $s_i, s_j$:

$$
\begin{array}{l}
	Q &=&
	\displaystyle
	\frac{1}{2m}
	\sum_{ij} \left(
		A_{ij} - 
		\frac{k_ik_j}{2m}
	\right)\delta_{g_i g_j} \\
	&=&
	\displaystyle
	\frac{1}{2m}
	\sum_{ij}B_{ij}\delta_{g_i g_j} \\
	&=&
	\displaystyle
	\frac{1}{4m}
	\sum_{ij}B_{ij} (s_is_j + 1)
\end{array}
$$

- $B_{ij}$: Represent the network. $$B_{ij} = A_{ij} - \frac{k_ik_j}{2m}$$
- $s_i$, $s_j$: A division of group. $$s_i = \left\{ \begin{array}{l} +1, & \text{if node } i \text{ belongs to group 1}  \\ -1, & \text{if node } i \text{ belongs to group 2}\end{array} \right.$$ The $s_i, s_j$ and the relationship with [[Kronecker Delta]] $\delta_{g_i g_j}$: $$\delta_{g_ig_j} = \frac 1 2 (s_i s_j + 1) = \left\{\begin{array}{rl}1, & \text{if } i \text{ and } j \text{ belong to}\\ & \text{the same group} \\ 0,& \text{otherwise}\end{array} \right.$$

This simplification can simplify the [[Modularity Maximization|modularity maximization problem]] into assigning $s_i = \pm 1$ to make $Q$ maximum.

---

# Reference

1. Lou, Yang. “Network Science, Lecture 7: Community Structure.” NYCU ED102[GF], November 7, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.