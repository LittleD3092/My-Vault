標籤: #DataStructure 

---

[TOC]

---

- This representation uses a matrix to represent graph. 
- Assume the graph $G = (V, E)$ has $n$ vertices, $n \geq 1$. The adjacency matrix is a two dimentional $n \times n$ array $a$. $a[i][j] = 1$ iff the edge $(i, j)$ or $<i, j>$ is in $E(G)$. $a[i][j] = 0$ if no such edge exists.
- The matrix $a$ is symmetry for undirected graph, but may not be symmetry for directed graph.
- It takes $O(n^2)$ time to answer non-trivial questions, such as how many edges are there in $G$?

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.