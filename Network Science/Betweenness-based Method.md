Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

We may use [[Betweenness Centrality|betweenness]] to identify the between-group edges, then identify communities. (<u>1</u>)

![[Pasted image 20231118135011.png|400]]

# Steps

The steps of betweenness-based method: (<u>1</u>)

1. Calculate betweenness of all edges.
2. Remove the edge with the highest betweenness.
3. Recalculate and remove desired number of rounds.

# Time Complexity

The time complexity of one round is: (<u>1</u>)

$$O(mn(m + n))$$

Or for a sparse network: (<u>1</u>)

$$O(n^3)$$

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.