Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

This algorithm serves the **first coming** process first.

For example, there are three processes:

| Process | Burst Time |
| ------- | ---------- |
| $P_1$   | $24$       |
| $P_2$   | $3$        |
| $P_3$   | $3$        | 

The [[Gantt Chart|Gantt chart]] for the schedule will be:

![[Pasted image 20231023160711.png|400]]

You can see that the average waiting time is long, since we can do better by doing $P_2$ and $P_3$ first.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.