標籤: #algorithm #DataStructure 

---

[TOC]

---

Binomial heap is a data structure that acts as a [[Heap]]. A difference is that binomial heap allows pairs of heaps to be merged.

# Structure

## Binomial Tree

A binomial heap is implemented as a set of binomial tree.

### Definition

A binomial tree is defined recursively as follows:

- A binomial tree of order $0$ is a single node.
- A binomial tree of order $k$ has a root node whose children are roots of binomial trees of orders $k - 1$, $k - 2$, $\dots$, $2$, $1$, $0$ (in this order).

![[Pasted image 20221203151338.png]]

### Property

Assume a binomial tree of order $k$.

- It has $2^k$ nodes.
- It has height $k$.
- It has $\displaystyle \binom{k}{d}$ nodes at depth $d$.
> $\displaystyle \binom{k}{d}$ means binomial coefficient. It has the same value as $C^k_d$, or $\displaystyle \frac{k!}{d!(k - d)!}$.
- Can be constructed from two trees of order $k - 1$ by attaching one of them as the leftmost child of the other tree.

## Binomial Heap

A binomial heap is a set of [[#Binomial Tree]] that satisfy:

- Each binomial tree in the binomial heap is a minimum [[Heap]].
- There can be at most one binomial tree for each order, including $0$ order.

An example:

![[Pasted image 20221203152508.png]]

# Implementation

- No operation requires random access, so the roots of binomial trees can be stored in a [[Linked List]].
- Since the number of children for a node is unknown, it is common to implement this tree using *links from each node to its highest-order child* in the tree, and to *its sibling* of the next smaller order than it.

## Merge Operation

![[Pasted image 20221203153046.png|300]]

Merging is simple. 

1. Compare the value of roots of the two trees.
2. The one with bigger root merge as a children.

$$
\begin{array}{l}
	\textbf{function} \text{ mergeTree}(p, q) \\
	\qquad \textbf{if } p.root.key \leq q.root.key \\
	\qquad \qquad \textbf {return } p.\text{addSubTree}(q) \\
	\qquad \textbf{else} \\
	\qquad \qquad \textbf{return } q.\text{addSubTree}(p)
\end{array}
$$

---

參考資料:

[Binomial Heap - wiki](https://en.wikipedia.org/wiki/Binomial_heap)

---

link:

[[Tree]]
[[Heap]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.