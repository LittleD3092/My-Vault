標籤: #algorithm 

---

[TOC]

---

We have a set $S = \{a_1, a_2, \dots, a_n\}$ of $n$ proposed activities, which we can do one at a time. Each activity $a_i$ has a start time $s_i$ and a finish time $f_i$. Select a maximum-size subset of activities that do not overlap.

- We assume that **the activities are sorted in monotonically increasing order of finish time**
$$f_1 \leq f_2 \leq f_3 \leq \dots \leq f_{n - 1} \leq f_n$$

> The activities sorted in increasing order of finish time is important.

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

If we denote the size of an optimal solution for the set $S_{ij}$ by $c[i, j]$, then it will be

$$
c[i, j] = 
\left\{
	\begin{array}{l}
		0 & \text{if } S_{ij} \neq \varnothing \\
		\displaystyle \underset{a_k \in S_{i, j}}{\text{max}} \{c[i, k] + c[k, j] + 1\} &
		\text{if } S_{ij} \neq \varnothing
	\end{array}
\right.
$$

At this point, we can use [[Divide-and-Conquer Approach]] to get our solution. But is there a better way than [[Divide-and-Conquer Approach]]?

# Making the Greedy Choice

What if we could choose an activity without solving all the subproblems?

We can choose the activity that leaves the resource available for as many other activities as possible. Which is the one with ==earliest finish time==.

> At the beginning of the note:
> We assume that the activities are sorted in monotonically increasing order of finish time.

Therefore the optimal choice will be $a_1$. Also, we have find out that this problem has [[#Optimal Substructure]], so the next choice will be in $S_{1j}$.

## Theorem

For subproblem $S_k$, the activity that has the earliest finish time $a_m$ is in our answer.

### Proof

- Let $A_k$ be the answer in $S_k$, and $a_j$ is the activity of earliest finish time in $A_k$, $a_j \neq a_m$.
- Let $A_k'$ be $A_k - \{a_j\} \cup \{a_m\}$.

Since $\vert A_k' \vert = \vert A_k \vert$, $A_k'$ is also an answer.

# Pseudocode

## Recursive

$$
\begin{array}{l}
	& \text{RECURSIVE-ACTIVITY-SELECTOR}(s, f, k, n) \\
	1 & m = k + 1 \\
	2 & \textbf{while } m \leq n \text{ and } s[m] < f[k] \qquad \text{// find the first activity in } S_k \text{ to finish} \\
	3 & \qquad m = m + 1 \\
	4 & \textbf{if } m \leq n \\
	5 & \qquad \textbf{return } \{a_m\} \cup \text{RECURSIVE-ACTIVITY-SELECTOR}(s, f, m, n) \\
	6 & \textbf{else return }\varnothing
\end{array}
$$

- $s$: array of starting time
- $f$: array of finishing time
- $k$: defines the subproblem $S_k$, which is max activities after activity $a_k$
- $n$: total number of tasks

## Iterative

$$
\begin{array}{l}
	& \text{GREEDY-ACTIVITY-SELECTOR}(s, f) \\
	1 & n = s.length \\
	2 & A = \{a_1\} \\
	3 & k = 1 \\
	4 & \textbf{for } m = 2 \textbf{ to } n \\
	5 & \qquad \textbf{if } s[m] \geq f[k] \\
	6 & \qquad \qquad A = A \cup \{a_m\} \\
	7 & \qquad \qquad k = m \\
	8 & \textbf{return }A
\end{array}
$$

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.