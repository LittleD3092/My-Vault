標籤: #algorithm #DataStructure 
Previous: [[Graph]]

---

[TOC]

---

If we have the graph below, and we want to find out the shortest path starting from `1`:

![[shortest distance example graph - graph.jpeg|400]]

We get the following table:

| chosen vertex | 1     | 2        | 3        | 4        | 5        | 6        | Description                                                                                                                                                   |
| ------------- | ----- | -------- | -------- | -------- | -------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1             | ==0== | $\infty$ | $\infty$ | $\infty$ | $\infty$ | $\infty$ | Starting with vertex `1`, we choose it                                                                                                                        |
| 2             | ==0== | ==2==    | 4        | $\infty$ | $\infty$ | $\infty$ | `1 -> 2` has weight `2` and `0 -> 3` weight `3`, both smaller than its previous distance $\infty$. We choose `2` this time because it has the least distance. |
| 3             | ==0== | ==2==    | ==3==    | 9        | $\infty$ | $\infty$ | `2 -> 3` has weight `1`, the distance of `3` can be reduced to `dis[2] + 1`, which is `3`. Also we relax distance of `4`.                                     |
| 5             | ==0== | ==2==    | ==3==    | 9        | ==6==    | $\infty$ |                                                                                                                                                               |
| 4             | ==0== | ==2==    | ==3==    | ==8==    | ==6==    | 11       |                                                                                                                                                               |
|               | ==0== | ==2==    | ==3==    | ==8==    | ==6==    | 9        |                                                                                                                                                               |

---

參考資料:

Fundamental of Data Structures in C++, 2nd edition
Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.