Tag: #operating-system 
Previous: [[Shortest Job First Scheduling]]
Link: 

[TOC]

---

Preemptive SJF not only schedules the process with less time, it **pauses a process** if some processes arrive and they have less time.

For example, the same 4 processes as above:

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| $P_1$   | $0.0$        | $7$        |
| $P_2$   | $2.0$        | $4$        |
| $P_3$   | $4.0$        | $1$        |
| $P_4$   | $5.0$        | $4$        | 

The [[Gantt Chart|Gantt chart]] will be:

![[Pasted image 20231023162439.png|400]]

The **average waiting time is minimum**.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.