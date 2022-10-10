標籤: #algorithm #list 

---

[TOC]

---

To solve a problem, some algorithms call themselves recursively one or more times to deal with closely related sub-problems. These algorithms typically follow a divide-and-conquer approach:

1. Divide the problem into a number of subproblems that are smaller instances of the same problem.
2. Conquer the subproblems by solving them recursively. If the subproblem sizes are small enough, however, just solve the subproblems in a straightforward manner.
3. Combine the solutions to the subproblems into the solution for the original problem.

For example, [[Merge Sort]] uses this approach. It operates as follows:

1. Divide: Divide the $n$-element sequence to be sorted into two subsequences of $n / 2$ elements each.
2. Conquer: Sort the two subsequences recursively using [[Merge Sort]].
3. Combine: Merge the two sorted subsequences to produce the sorted answer.

When the subproblems are large enough to solve recursively, we call that the ==recursive case==. Once the subproblems become small enough that we no longer recurse, we say that we have gotton down to the ==base case==.

# Analyze

The procedure of analyzing a divide-and-conquer approach often have the following recurrence:

If the problem size is small enough, say $n$ is smaller than a constant $c$, there is an obvious solution and it takes constant time.

Otherwise, it yields $a$ subproblems and each takes $T(n/b)$ time. Note that for some divide-and-conquer algorithm, $a \neq b$. We also take $D(n)$ time to divide the problem into subproblems and $C(n)$ time to combine the solutions to the original problem.


$$T(n) = 
\left\{
	\begin{array}{l}
		\Theta(1) & \text{if } n \leq c, \\
		aT(n / b) + D(n) + C(n) & \text{otherwise.}
	\end{array}
\right.$$

# Algorithms

This section show some algorithms and problems that use divide-and-conquer approach.

- [[Merge Sort]]
- [[53. Maximum Subarray]]
- [[121. Best Time to Buy and Sell Stock]]
- [[Matrix Multiplication]]

---

參考資料:

Introduction to Algorithms, third edition

---

link:

[[Merge Sort]]
[[Recursion]]