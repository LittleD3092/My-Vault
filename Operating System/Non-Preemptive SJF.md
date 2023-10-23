Tag: #operating-system 
Previous: [[Shortest Job First Scheduling]]
Link: 

[TOC]

---

Non-Preemptive SJF puts the process that requires less time first, but it **won't pause a process** if some other process with less time appears.

For example, there are 4 processes with arbitrary arrival time:

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| $P_1$   | $0.0$        | $7$        |
| $P_2$   | $2.0$        | $4$        |
| $P_3$   | $4.0$        | $1$        |
| $P_4$   | $5.0$        | $4$        | 

The [[Gantt Chart|Gantt chart]] will be:

![[Pasted image 20231023161848.png|400]]

Note that **the average waiting time isn't the minimum**, because the process $P_1$ blocks the other processes.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.