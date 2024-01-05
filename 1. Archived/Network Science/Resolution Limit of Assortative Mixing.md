Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

A problem of assortative mixing is that it is unable to see communities if they are too small. (<u>1</u>)

For the following example, we see two small fully-connected groups: (<u>1</u>)

![[Pasted image 20231118134126.png|250]]

It is clear that these groups should be separated. But using the [[Assortative Mixing|assortative mixing]] and trying to move the two groups together: (<u>1</u>)

$$\Delta Q = \frac{1}{2m}\left(
	1 - \frac{\kappa_1 \kappa_2}{2m}
\right)$$

- $\kappa_1, \kappa_2$: The number of intra-degrees.
- $m$: The number of nodes.

Because for large network and small clique, (<u>1</u>)

$$\kappa_1 \kappa_2 < 2m$$

Therefore, (<u>1</u>)

$$\Delta Q > 0$$

and the [[Assortative Mixing|assortative mixing]] method suggests that we merge the 2 groups together. (<u>1</u>)

From the above example, we can see that if the product of the degree sums is less than the total degree, modularity maximization will fail to distinguish then as different communities. (<u>1</u>)

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.