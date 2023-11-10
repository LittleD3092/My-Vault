Tag: #network-science 
Previous: [[Assortative Mixing]]
Link: 

[TOC]

---

The formula of assortative mixing uses two equations: (<u>1</u>)

- [[Actual Intra-edges of Network with Unordered Features|Actual Intra-edges]] $$\sum_{\rm edges(i, j)}\delta_{g_ig_j} = \frac 1 2 \sum_{ij}A_{ij}\delta_{g_i g_j}$$
	- [[Kronecker Delta]]
- [[Expected Intra-edges of Network with Unordered Features|Expected Intra-edges]] $$\frac 1 2 \sum_{ij}\frac{k_i k_j}{2m} \delta_{g_ig_j}$$

Subtracting the above 2 equations, we get the difference of expected and actual intra-edges, which is "score" $Q$: (<u>1</u>)

$$\frac 1 2 \sum_{ij} A_{ij}\delta_{g_ig_j} - \frac 1 2 \sum_{ij}\frac{k_i k_j}{2m}\delta_{g_ig_j} = \frac 1 2 \sum_{ij}\left(
	A_{ij} - \frac{k_i k_j}{2m}
\right)\delta_{g_i g_j}$$

$$
Q = \frac{1}{2m} \sum_{ij} \left(
	A_{ij} - \frac{k_ik_j}{2m}
\right) \delta_{g_ig_j}
$$

- $Q > 0$: More edges between same label.
- $Q < 0$: More edges between different label.

Related topics:

- [[Simplification of Assortative Mixing with Unordered Features]]

---

# Reference

1. Lou, Yang. “Network Science, Lecture 7: Community Structure.” NYCU ED102[GF], November 7, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.