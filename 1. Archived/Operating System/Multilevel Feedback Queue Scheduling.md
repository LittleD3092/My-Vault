Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

This algorithm is based on the [[Multilevel Queue Scheduling]]. This method adds the functionality to **move processes between queues**.

The scheduler can be defined using the parameters following:

- Number of **queues**.
- **Scheduling algorithms** for each queue.
- Method to determine when to **promote** and **demote** a class.
- Method to determine the queue a process will **enter initially**.

This method **promote IO bound process**, and **demote CPU bound process**. In this way, we improve IO utilization and improve the CPU throughput.

# Example: 3-level Queue

For example, a 3-level feedback queue might look like the following:

Three queues are defined:

| Queue | Method and Time Quantum                                          |
| ----- | ---------------------------------------------------------------- |
| $Q_0$ | [[Round Robin Scheduling]] with time quantum $q = 8\text{ms}$.   | 
| $Q_1$ | [[Round Robin Scheduling]] with time quantum $q = 16 \text{ms}$. |
| $Q_2$ | [[First-Come, First-Served Scheduling]].                         |

The rules:

- A job initially enters $Q_0$.
- A job failing to complete [[CPU Burst]] in a queue gets demoted to the next queue.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.