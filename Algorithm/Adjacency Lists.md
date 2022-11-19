標籤: #DataStructure 

---

[TOC]

---

- Because the [[#Adjacency Matrices]] have some spaces unused, in some cases it would be a waste of space if we implement graph using [[#Adjacency Matrices]]. So we may use an array of lists, which each list stores only the edges linked.
- Below is the representation for the example graphs.

![[example graph g1 - graph.jpeg|200]]
![[example graph g3 - graph.jpeg|100]]
![[example graph g4 - graph.jpeg|300]]
![[adjacent lists example - graph.jpeg|400]]

### Sequential Array

We can also store a [[#Adjacency Lists]] in a sequential array. The figure below shows the sequential representation of graph $G_4$:

![[example graph g4 - graph.jpeg|300]]

![[sqeuqntial representation of example graph g4 - graph.jpeg|600]]

`nodes[0:8]` act as a "index" of where the [[#Adjacency Lists]] begin. For example, `nodes[9]` and `nodes[10]` is the edge of vertex `0`.

### Inverse Adjacency Lists

If we need to keep track of the in-degree more than the out-degree, we use inverse adjacency lists, shown below.

![[example graph g3 - graph.jpeg|100]]

![[inverse adjacency lists for g3 - graph.jpeg|500]]

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.