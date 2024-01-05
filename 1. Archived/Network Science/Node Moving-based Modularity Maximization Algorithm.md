Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

The core concept of this algorithm is to try to change groups of nodes, and see whether the modularity increases. The modularity is calculated using [[Assortative Mixing|assortative mixing score]]. (<u>1</u>)

The steps of this method is listed below: (<u>1</u>)

1. Divide the nodes into 2 equal size groups at random.
2. Repeat the following steps for desired rounds.
	1. Calculate the modularity change for each node to change group.
	2. Choose one from all nodes with the most modularity increase (or least modularity decrease), and change its group.

This method has a per-round complexity: (<u>1</u>)

$$O(n(m + n))$$

which is considered large. (<u>1</u>)

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.