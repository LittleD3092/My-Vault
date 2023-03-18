標籤: #algorithm 

---

[TOC]

---

There are two kinds of knapsack problem. They are silightly different, but they require different solution.

1. [[#0-1 Knapsack Problem]]: Must use [[Divide-and-Conquer Approach]]
2. [[#Fractional Knapsack Problem]]: Can use [[Greedy Algorithm]]

# 0-1 Knapsack Problem

A thief robbing a store finds $n$ items. The $i$th item is worth $v_i$ dollars and weighs $w_i$ pounds. The thief wants to take as valuable a load as possible, but he can carry at most $W$ pounds in his knapsack. ==For each item, he must take it or leave it behind.== Which items should he take?

## Optimal Substructure

Consider the most valuable load that weighs at most $W$ pounds.

If we remove item $j$ from this load, the remaining load must be the most valuable load weighing at most $W - w_j$ that the thief can take from the $n - 1$ original items excluding $j$.

## Why greedy does not work

Consider the items and the knapsack:

![[Pasted image 20221111164451.png|250]]

By greedy, we may choose item 1. But the item 1 is actually not in the optimal solution:

![[Pasted image 20221111164639.png|250]]

# Fractional Knapsack Problem

A thief robbing a store finds $n$ items. The $i$th item is worth $v_i$ dollars and weighs $w_i$ pounds. The thief wants to take as valuable a load as possible, but he can carry at most $W$ pounds in his knapsack. ==The thief can take fractions of items.== Which items should he take?

## Optimal Substructure

Consider the most valuable load that weighs at most $W$ pounds.

If we remove a weight $w$ of one item $j$ from the optimal load, the remaining load must be the most valuable load weighing at most $W - w$ that the thief can take from the $n - 1$ original items plus $w_j - w$ pounds of item $j$.

## Solution

1. We first compute the value per pound $v_i / w_i$ for each item.
2. Obeying a greedy strategy, the thief begins by taking as much as possible of the item with the greatest value per pound.
3. If the supply of that item is exhausted and he can still carry more, he takes as much as possible of the item with the next greatest value per pound, until he reaches his weight limit $W$.

### Time Complexity

By sorting the items based on the value per pound $v_i/w_i$, it takes $O(n\lg n)$.

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.