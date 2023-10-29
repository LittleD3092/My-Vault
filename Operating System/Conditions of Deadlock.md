Tag: #operating-system 
Previous: [[Deadlock of Semaphore]]
Link: 

[TOC]

---

There are 4 conditions that happens simultaneously when deadlock happens. If one of the 4 is not satisfied, the deadlock won't happen. (<u>1</u>)

1. **Mutual exclusion**: Only one process at a time can use a resource.
2. **Hold and wait**: A process is holding at least one resource and waiting for other resources.
3. **No preemption**: A resource can only be released by the process using it. Even a higher priority process can't release it.
4. **Circular wait**: There exist a set $\{P_0, P_1, \dots, P_n\}$ of processes that $P_i$ is waiting for a resource held by $P_{(i + 1)\% n}$.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 7: Deadlocks.” NYCU EC122[GF], October 25, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.