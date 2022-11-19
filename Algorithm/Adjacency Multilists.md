標籤: #DataStructure 

---

[TOC]

---

In this list, each edge will be exactly one node, shared by two vertices. The node is like the following:

| `m` | `vertex1` | `vertex2` | `link1` | `link2` | 
| --- | --------- | --------- | ------- | ------- |

- `m`: A boolean field to indicate whether this edge has been examined.
- `vertex1`, `vertex2`: The vertices of the edge
- `link1`: The `*next` pointer for `vertex1`
- `link2`: The `*next` pointer for `vertex2`

Below is an example of graph $G_1$:

![[example graph g1 - graph.jpeg|200]]

![[adjacency multilists for g1 - graph.jpeg|600]]

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.