標籤: #algorithm 

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

---

參考資料:

Introduction to Algorithms, third edition

---

link:

[[Merge Sort]]