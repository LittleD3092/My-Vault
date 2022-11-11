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

# Activity Selection Problem

[[Activity Selection Problem]]

# Greedy vs Dynamic Programming

You may be tempted to generate a dynamic-programming solution to a problem when a greedy solution suffices or, conversely, you might mistakenly think that a greedy solution works when in fact a dynamic-programming solution is required.

## Knapsack Problem

To illustrate the subtleties between the two techniques, let us investigate two variants of a classical optimization problem [[Knapsack Problem]].

# Huffman Codes

[[Huffman Coding]]

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Dynamic Programming]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.