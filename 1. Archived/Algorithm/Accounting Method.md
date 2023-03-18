標籤: #algorithm 

---

[TOC]

---

In the accounting method of amortized analysis, we assign differing charges to different operations, with some operations charged more or less than they actually cost. The amount we charge an operation is called its **amortized cost**.

When an operation's amortized cost exceeds its actual cost, we assign the difference to specific objects in the data structure as **credit**.

# Example

## Stack Example

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

The actual costs of the operations were

$$
\begin{array}{l}
	\text{Push} & 1 \\
	\text{Pop} & 1 \\
	\text{Multipop} & \min(k, s)
\end{array}
$$

Let us assign the following amortized costs:

$$
\begin{array}{l}
	\text{Push} & 2 \\
	\text{Pop} & 0 \\
	\text{Multipop} & 0
\end{array}
$$

For every element pushed on the stack, it has $2 - 1 = 1$ dollar on it. The money acts as a prepayment.

If we wish to $\text{Pop}$ or $\text{Multipop}$, we can simply take the dollar on the element and pay for the cost. 

Since each element on the stack has $1$ dollar of credit on it, and the stack always has a nonnegative number of plates, we have ensured that the amount of credit is always nonegative.

Thus, for any sequence of $n$ operations, the total amortized cost is an upper bound on the total actual cost. The total amortized cost is $O(n)$.

## Incrementing a Binary Counter

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

Let us charge an amortized cost of $2$ dollars to set a bit to $1$.

When a bit is set, we use $1$ dollar out of $2$ dollars amortized cost to pay for the actual setting of the bit, and we place the other dollar on the bit.

At any point in time, every $1$ in the counter has a dollar of credit on it, and thus we can charge nothing to reset a bit to $0$.

We see that $\text{Increment}$ procedure sets at most one bit, and therefore the amortized cost is at most $2$ dollars. The amount of credit stays nonnegative at all times.

Thus, for $n$ $\text{Increment}$ operations, the total amortized cost is $O(n)$.

---

參考資料:

Introduction to Algorithm, 3rd edition

---

link:

[[Asymptotic Notation]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.