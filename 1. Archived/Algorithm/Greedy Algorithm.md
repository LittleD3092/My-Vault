標籤: #algorithm #list 

---

[TOC]

---

A greedy algorithm always makes the choice that looks best at the moment. That is, it makes a locally optimal choice in the hope that this choice will lead to a globally optimal solution.

# Steps

We may see from [[#Activity Selection Problem]] that developing a greedy algorithm involves the following steps:

1. Cast the optimization problem as one in which we make a choice and are left with one subproblem to solve.
2. Prove that there is always an optimal solution to the original problem that makes the greedy choice, so that the greedy choice is always safe.
3. Demonstrate optimal substructure by showing that, having made the greedy choice, what remains is a subproblem with the property that if we combine an optimal solution to the subproblem with the greedy choice we have made, we arrive at an optimal solution to the original problem.

# Greedy vs Dynamic Programming

You may be tempted to generate a dynamic-programming solution to a problem when a greedy solution suffices or, conversely, you might mistakenly think that a greedy solution works when in fact a dynamic-programming solution is required.

## Knapsack Problem

To illustrate the subtleties between the two techniques, let us investigate two variants of a classical optimization problem [[Knapsack Problem]].

# Activity Selection Problem

> [[Activity Selection Problem]]

# Huffman Codes

> [[Huffman Coding]]

# Matroids with Greedy

> [[Matroid]]

## Weighted Matroid

> The algorithm for solving minimum cost spanning tree is here:
> [[Minimum Cost Spanning Tree]]

If the problem can be modelled into a matroid, it can be solved like [[Minimum Cost Spanning Tree]].

The following pseudocode provide an algorithm for solving matroid. The algorithm is called [[Minimum Cost Spanning Tree#Kruskal's Algorithm|Kruskal's Algorithm]].

$$
\begin{array}{l}
	& \text{Greedy}(M, w) \\
	1 & A = \varnothing \\
	2 & \text{sort } M.S \text{ into monotonically decreasing order by weight }w \\
	3 & \textbf{for } \text{each } x \in M.S, \text{ taken in monotonically decreasing order by weight }w(x) \\
	4 & \qquad \textbf{if } A\cup \{x\} \in M.\mathcal I \\
	5 & \qquad \qquad A = A \cup \{x\} \\
	6 & \textbf{return } A
\end{array}
$$

## Task-Scheduling Problem

An interesting problem that we can solve using matroids is the problem of optimally scheduling tasks.

> [[Task Scheduling Problem]]

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Dynamic Programming]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.