標籤: #algorithm 

---

[TOC]

---

Instead of representing prepaid work as credits placed on the object in [[Accounting Method]], the potential method represents the prepaid work as "potential evergy".

The potential method work as follows:

1. We will perform $n$ operations, starting with an initial data structure $D_0$.
2. For each $i = 1, 2, \dots, n$, we let $c_i$ be the actual cost of the $i$th operation and $D_i$ be the data structure that results after applying the $i$th operation to data structure $D_{i - 1}$.
3. A **potential function** $\Phi$ maps each data structure $D_i$ to a real number $\Phi(D_i)$.
4. The **amortized cost** $\hat c_i$ of the $i$th operation with respect to potential function $\Phi$ is defined by
$$\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i - 1})$$
5. The total amortized cost will be
$$\sum_{i = 1}^n \hat c_i = \sum_{i = 1}^n(c_i + \Phi(D_i) - \Phi(D_{i - 1}))$$
$$= \sum_{i = 1}^n c_i + \Phi(D_n) - \Phi(D_0)$$

If we can prove that $\Phi(D_n) \geq \Phi(D_0)$, then the total amortized cost gives an upper bound on the total actual cost.

# Examples

## Stack Operations

### Algorithm

The algorithm of stack operations includes the following operations:

1. $\text{Push}(S, x)$
	- Pushes object $x$ onto stack $S$.
	- Requires $O(1)$ time.
2. $\text{Pop}(S)$
	- Pops the top of stack $S$ and returns the popped object. 
	- Calling $\text{Pop}$ on an empty stack generates an error.
	- Requires $O(1)$ time.
3. $\text{Multipop}(S, k)$
	- Removes the $k$ top objects of stack $S$.
	- Popping the entire stack if the stack contains fewer than $k$ objects.
	- Requires $\min(s, k)$ time, which $s$ is the size of $S$. Therefore, the time complexity is $O(n)$.

### Analysis

We define the potential function $\Phi$ on a stack to be the number of objects in the stack. $D_0$ has $\Phi(D_0) = 0$, because it is empty.

Since the number of objects 

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Asymptotic Notation]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.