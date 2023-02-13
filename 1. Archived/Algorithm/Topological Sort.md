標籤: #algorithm 

---

[TOC]

---

Suppose we have a graph, find an ordering of vertices so that all of the dependency requirements are met.

For example, we may organize the graph above to the graph below:

![[Pasted image 20221119175331.png]]

> Note that if the graph contains a cycle, then no linear ordering is possible.

# Algorithm

The following simple algorithm topologically sorts a dag:

$$
\begin{array}{l}
	& \text{Topological-Sort}(G) \\
	1 & \text{call DFS}(G) \text{ to compute finishing times } v.f \text{ for each vertex }v \\
	2 & \text{as each vertex is finished, insert it onto the front of a linked list} \\
	3 & \textbf{return } \text{the linked list of vertices}
\end{array}
$$

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.