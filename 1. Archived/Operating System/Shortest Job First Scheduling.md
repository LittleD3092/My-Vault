Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

This algorithm puts the process that **requires less time** first.

For example, there are four processes:

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| $P_1$   | $0.0$        | $6$        |
| $P_2$   | $0.0$        | $8$        |
| $P_3$   | $0.0$        | $7$        |
| $P_4$   | $0.0$        | $3$           |

The [[Gantt Chart|Gantt chart]] will be:

![[Pasted image 20231023161232.png]]

This method guarantees **minimum average waiting time**. However, this is **not a fair algorithm**, because processes with long CPU bursts may never get executed.

Depending on the [[CPU Scheduler]], we can do better by [[Preemptive Scheduling]]:

- [[Non-Preemptive SJF]]
- [[Preemptive SJF]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.