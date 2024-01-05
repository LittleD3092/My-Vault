Tag: #network-science 
Previous: [[Modularity Maximization]]
Link: 

[TOC]

---

Louvain algorithm is a greedy optimization method with a time complexity $O(n\cdot \log n)$. It can determine the [[Modularity Maximization|modularity maximization problem]] with **multiple groups**. (<u>1</u>)

# Steps

> Join single nodes into groups, then join groups with other groups. (<u>1</u>)

1. Treat each node as a separate group.
2. Try to move a chosen node to a group if the modularity increases.
3. Repeat step 2 until the modularity no longer increases.

# Time complexity

The time complexity of Louvain algorithm in a single round is: (<u>1</u>)

$$O(m + n)$$

The number of rounds is: (<u>1</u>)

$$O(\log n)$$

Combining these we can get the total time complexity: (<u>1</u>)

$$O((m + n)\log n)$$

Or for sparse networks: (<u>1</u>)

$$O(n\log n)$$

---

# Reference

1. Lou Yang. “Network Science, Lecture 7: Community Structure, part 2.” NYCU ED102[GF], November 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.