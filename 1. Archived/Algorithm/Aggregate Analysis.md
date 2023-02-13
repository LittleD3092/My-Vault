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

Although a single $\text{Multipop}$ operation can be expensive, because we can pop each object from the stack at most once for each time we have pushed it onto the stack, an initially empty stack can cost at most $O(n)$.

The average cost of an operation is 

$$O(n) / n = O(1)$$

Therefore, all three stack operations have an amortized cost of $O(1)$.

## Incrementing a Binary Counter

- We implement a $k$-bit binary counter that counts upward from $0$.
- The counter is represented by an array $A[0\dots k - 1]$, with a length $k$.
	- Lowest-order bit is in $A[0]$ and highest-order bit is in $A[k - 1]$.

### Algorithm

To add $1$ to the counter, we use the following procedure

$$
\begin{array}{l}
	& \text{Increment}(A) \\
	1 & i = 0 \\
	2 & \textbf{while } i < A.\textit{length} \text{ and } A[i] == 1 \\
	3 & \qquad A[i] = 0 \\
	4 & \qquad i = i + 1 \\
	5 & \textbf{if } i < A.\textit{length} \\
	6 & \qquad A[i] = 1
\end{array}
$$

The increment process should look like this:

$$
\begin{array}{}
	\begin{array}{}
		\text{Counter} \\
		\text{value}
	\end{array} &
	A[7] & A[6] & A[5] & A[4] & 
	A[3] & A[2] & A[1] & A[0] & 
	\begin{array}{}
		\text{Total} \\
		\text{cost}
	\end{array} \\
	0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
	1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 1 \\
	2 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 3 \\
	3 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 1 & 4 \\
	4 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 7 \\
	5 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 8 \\
	6 & 0 & 0 & 0 & 0 & 0 & 1 & 1 & 0 & 10 \\
	7 & 0 & 0 & 0 & 0 & 0 & 1 & 1 & 1 & 11 \\
	8 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 15 \\
	9 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 1 & 16 \\
	10 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 0 & 18 \\
	11 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 1 & 19 \\
	12 & 0 & 0 & 0 & 0 & 1 & 1 & 0 & 0 & 22 \\
	13 & 0 & 0 & 0 & 0 & 1 & 1 & 0 & 1 & 23 \\
	14 & 0 & 0 & 0 & 0 & 1 & 1 & 1 & 0 & 25 \\
	15 & 0 & 0 & 0 & 0 & 1 & 1 & 1 & 1 & 26 \\
	16 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 & 31
\end{array}
$$

### Analysis

#### Worst Case

A single execution of $\text{Increment}$ takes time $\Theta(k)$ in the worst case, in which array $A$ contains all $1$s. Thus, a sequence of $n$ $\text{Increment}$ operations on an initially zero counter takes time $O(nk)$ in the worst case.

As with the [[#Stack Operations]] example, we can do better.

#### Analysis

$A[0]$ is flipped each time. $A[1]$ flips only every other time. Similarly, bit $A[2]$ flips only every fourth time.

With the above observation, we can get the number of flips for each bit $A[i]$:

| Bit      | Time of Flips for Given $n$                              |
| -------- | -------------------------------------------------------- |
| $A[0]$   | $n$                                                      |
| $A[1]$   | $\displaystyle \left\lfloor \frac n 2 \right\rfloor$     |
| $A[2]$   | $\displaystyle \left\lfloor \frac n 4 \right\rfloor$     |
| $\vdots$ | $\vdots$                                                 |
| $A[i]$   | $\displaystyle \left\lfloor \frac n {2^i} \right\rfloor$ | 

The total number of flips in the sequence is thus

$$
\sum_{i = 0}^{k - 1} \left\lfloor
	\frac{n}{2!}
\right\rfloor <
n \sum_{i = 0}^{\infty} \frac{1}{2^i} = 2n
$$

The average cost of each operation, which is the amortized cost per operation, is

$$
\frac{O(n)}{n} = O(1)
$$

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Asymptotic Notation]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.