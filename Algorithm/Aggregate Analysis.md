標籤: #algorithm 

---

[TOC]

---

In aggregate analysis, we show that for a sequence of $n$ operations takes worst-case time $T(n)$ in total. Then, the **amortized cost** is therefore $T(n) / n$.

# Example

This section shows some algorithms and the process of aggregate analysis.

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

#### Worst Case

The worst-case cost of a $\text{Multipop}$ operation is $O(n)$, therefore the the worst-case time of any stack operation is therefore $O(n)$. Hence, a sequence of $n$ operations costs $O(n^2)$.

The $O(n^2)$ is correct, but it is not tight. Can we do better?

#### Aggregate Analysis



---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Asymptotic Notation]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.