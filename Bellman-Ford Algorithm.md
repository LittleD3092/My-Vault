標籤: #algorithm #DataStructure 

---

[TOC]

---

![[shortest distance example graph - graph.jpeg|400]]

To use Bellman-Ford algorithm, we have the following two steps:

1. List all edges.

| from | to  | weight |
| ---- | --- | ------ |
| 1    | 2   | 2      |
| 1    | 3   | 4      |
| 2    | 3   | 1      |
| 2    | 4   | 7      |
| 3    | 5   | 3      |
| 4    | 6   | 1      |
| 5    | 4   | 2      |
| 5    | 6   | 5      |

2. Relax all edges $(n - 1)$ times, where $n$ is the number of the vertices.

| k   | 1    | 2    | 3    | 4    | 5    | 6    |
| --- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1   | 0    | 2    | 3    | 8    | 6    | 10   |
| 2   | 0    | 2    | 3    | 8    | 6    | 9    |
| 3   | \`\` | \`\` | \`\` | \`\` | \`\` | \`\` |
| 4   | \`\` | \`\` | \`\` | \`\` | \`\` | \`\` |
| 5   | \`\` | \`\` | \`\` | \`\` | \`\` | \`\` |

> ### Negative Weight Cycle
> Note that Bellman-Ford does not solve negative weight cycles. In face, if we keep going around the negative cycle, we will have lower and lower costs.
> 
> Although we can't solve negative weight cycles, there is a way to check them. After we finish $(n - 1)$ times of relaxation using Bellman-Ford, we do it again and check whether the distance changes. If the distance changes, there is a negative cycle.

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition
Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.