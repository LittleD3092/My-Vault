標籤: #algorithm 

---

[TOC]

---

We have a set $S = \{a_1, a_2, \dots, a_n\}$ of $n$ proposed activities, which we can do one at a time. Each activity $a_i$ has a start time $s_i$ and a finish time $f_i$. Select a maximum-size subset of activities that do not overlap.

- We assume that the activities are sorted in monotonically increasing order of finish time
$$f_1 \leq f_2 \leq f_3 \leq \dots \leq f_{n - 1} \leq f_n$$

# Example Input

For example, $S$ may be

| $i$   | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$  | $8$  | $9$  | $10$ | $11$ |
| ----- | --- | --- | --- | --- | --- | --- | ---- | ---- | ---- | ---- | ---- |
| $s_i$ | $1$ | $3$ | $0$ | $5$ | $3$ | $5$ | $6$  | $8$  | $8$  | $2$  | $12$ |
| $f_i$ | $4$ | $5$ | $6$ | $7$ | $9$ | $9$ | $10$ | $11$ | $12$ | $14$ | $16$ | 



---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.