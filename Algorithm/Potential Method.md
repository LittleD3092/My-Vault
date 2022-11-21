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

We define the potential function $\Phi$ on a stack to be the number of objects in the stack. $D_0$ has $\Phi(D_0) = 0$, because it is an empty stack.

Since the number of objects in the stack is never negative, the stack $D_i$ that results after the $i$th operation has nonnegative potential, and thus

$$\Phi(D_i) \geq 0$$

For $\text{Push}$ operation, 

$$\Phi(D_i) - \Phi(D_{i - 1}) = (s + 1) - s = 1$$

The amortized cost is

$$\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i - 1})$$
$$ = 1 + 1 = 2$$

For $\text{Multipop}$ operation,

$$\Phi(D_i) - \Phi(D_{i - 1}) = -k'$$

The amortized cost is

$$\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i - 1})$$

$$ = k' - k'  = 0$$

Similarly, the amortized cost for $\text{Pop}$ operation is $0$.

The amortized cost of each of the three operations is $O(1)$, and thus the total amortized cost of a sequence of $n$ operations is $O(n)$. Since we proved that $\Phi(D_i) \geq \Phi(D_0)$, the worst-case cost of $n$ operations is therefore $O(n)$.

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

Suppose the $i$th operation has a potential $b_i$ and resets $t_i$ bits. $b_i$ is the number of ones after the operation.

The actual cost is at most $t_i + 1$, since in addition to resetting $t_i$ bits, it sets at most one bit to $1$.

If $b_i = 0$, then the $i$th operation resets all $k$ bits, and so $b_{i - 1} = t_i = k$.
If $b_i > 0$, then $b_i = b_{i - 1} - t_i + 1$.
In either case, $b_i \leq b_{i - 1} - t_i + 1$.
So the total difference is

$$\Phi(D_i) - \Phi(D_{i - 1}) \leq (b_{i - 1} - t_i + 1) - b_{i - 1} = 1 - t_i$$

The amortized cost is therefore

$$\hat c_i = c_i + \Phi(D_i) - \Phi(D_{i - 1})$$
$$\leq (t_i + 1) + (1 - t_i)$$
$$ = 2$$

If the counter start at $0$, $\Phi(D_0) = 0$. 
Because the counter never has negative number of ones, $\Phi(D_i)\geq 0$.
Because the above condition, the amortized cost is an upper bound.
The worst case of $n$ operations is

$$O(n)$$

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Asymptotic Notation]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.