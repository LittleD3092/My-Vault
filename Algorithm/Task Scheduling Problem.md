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

---

參考資料:

Introduction to Algorithms, 3rd edition

---

link:

[[Matroid]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.