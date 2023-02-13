標籤: #algorithm 

---

[TOC]

---

# Unit-Time Task Scheduling

Given a finite set $S$ of unit-time tasks, a ==schedule== for $S$ is a permutation of $S$ specifying the order in which to perform these tasks. Each task has a deadline, along with a penalty paid if the task misses its deadline. Find the permutaion with least penalty paid.

Inputs:

- a set $S = \{a_1, a_2, \dots, a_n\}$ of $n$ unit-time tasks
- a set of $n$ integer ==deadlines== $d_1, d_2, \dots, d_n$, such that each $d_i$ satisfies $1 \leq d_i < n$ and task $a_i$ is supposed to finish by time $d_i$
- a set of $n$ nonnegative weights or ==penalties== $w_1, w_2, \dots, w_n$, such that we incur a penalty of $w_i$ if task $a_i$ is not finished by time $d_i$, and we incur no penalty if a task finishes by its deadline.

## Matroid Model

We said that a set $A$ of tasks is ==independent== if there exists a schedule for these tasks such that no tasks are late.
Let $\mathcal I$ denote the set of all independent sets of tasks.

For $t = 0, 1, 2, \dots, n$, let $N_t(A)$ denote the number of tasks in $A$ whose deadline is $t$ or earlier.

For any set of tasks $A$, the following statements are equivalent.
1. The set $A$ is independent.
2. For $t = 0, 1, 2, \dots, n$, we have $N_t(A) \leq t$.
3. If the tasks in $A$ are scheduled in order of monotonically increasing deadlines, then no task is late.

> To prove the exchange property of $\mathcal I$, suppose that $B$ and $A$ are independent sets of tasks and that $\vert B \vert > \vert A \vert$.
> 
> Let $k$ be the largest $t$ that 
> 
> $$N_t(B) \leq N_t(A)$$
> 
> Since
> 
> $$N_n(B) = \vert B \vert$$
> $$N_n(A) = \vert A \vert$$
> but
> $$\vert B \vert > \vert A \vert$$
> $$\implies N_n(B) > N_n(A)$$
> We must have $k < n$.
> 
> Therefore,
> $$N_{k + 1}(B) > N_{k + 1}(A)$$
> Let $a_i$ be the task in $B - A$ with deadline $k + 1$.
> Let $A' = A \cup \{a_i\}$.
> It is obvious that $A'$ is also an independent set.
> Therefore, this is a matroid.

By the above proof, we see that if $S$ is a set of unit-time tasks with deadlines, and $\mathcal I$ is the set of all independent sets of tasks, then the corresponding system $(S, \mathcal I)$ is a [[Matroid]].

We can use $\text{Greedy}(M, w)$ as our algorithm, which $w$ is the penalty array.

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

## Example

Input: 

| $a_i$ | $1$  | $2$  | $3$  | $4$  | $5$  | $6$  | $7$  |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| $d_i$ | $4$  | $2$  | $4$  | $3$  | $1$  | $4$  | $6$  |
| $w_i$ | $70$ | $60$ | $50$ | $40$ | $30$ | $20$ | $10$ | 

1. Accept $a_1$ to $a_4$.
2. Reject $a_5$ because $N_4(\{a_1, a_2, a_3, a_4, a_5\}) = 5$. 
3. Reject $a_6$ because $N_4(\{a_1, a_2, a_3, a_4, a_6\}) = 5$. 
4. Accept $a_7$.
5. The final optimal schedule is $<a_2, a_4, a_1, a_3, a_7, a_5, a_6>$ with total penalty $w_5 + w_6 = 50$.

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Matroid]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.