Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

Raddicchi's method suggest that shortest loops are unlikely to be inter-connected edges. As the figure below, short loops 1 and 2 are not inter-connected edges. (<u>1</u>)

![[Pasted image 20231118135642.png|400]]

Related topics:

- [[Similarity of Node in Network]]
	- [[Structural Equivalence]]
	- [[Regular Equivalence]]
	- [[Cosine Similarity]]

# Steps

1. Evaluate [[Similarity of Node in Network|similarity]] of all node pairs.
2. Each node is assigned a group. A group can be considered a single node when calculating [[Similarity of Node in Network|similarity]].
3. Find the pair of groups with the highest similarity and join them into a single group.
4. Evaluate [[Similarity of Node in Network|similarity]] of all group pairs.
5. Go to group 3 until all nodes are joined into a single group.

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.