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

# Optimal Substructure

In this section, we will show that this problem has a optimal substructure.

We say $S_{ij}$ is the set of activities that start after activity $a_i$ finishes and that finish before activity $a_j$ starts.

Suppose $A_{ij}$ is the maximum set of mutually compatible activities in set $S_{ij}$, and $A_{ij}$ include some activity $a_k$.

By including $a_k$ in an optimal solution, we have two subproblems:
1. Find mutually compatible activities $A_{ik}$ in the set $S_{ik}$.
2. Find mutually compatible activities $A_{kj}$ in the set $S_{kj}$.

So that

$$
\left\{
	\begin{array}{}
		A_{ik} = A_{ij} \cap S_{ik} \\
		A_{kj} = A_{ij} \cap S_{kj}
	\end{array}
\right.
$$

Thus, the optimal solution will be

$$A_{ij} = A_{ik} \cup \{a_k\} \cup A_{kj}$$

$$\implies \vert A_{ij} \vert = \vert A_{ik}\vert + 
\vert A_{kj} \vert + 1$$

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.