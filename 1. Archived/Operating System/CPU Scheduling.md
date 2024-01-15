Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

The process often executes with CPU burst and IO burst alternating, like the figure below:

![[Pasted image 20231021200841.png|300]]

In practice, the majority of CPU bursts are short. Therefore, we need a CPU scheduler to choose processes that need CPU time, and let other processes wait for IO.

- [[CPU Scheduler]]
	- [[Cooperative Scheduling]]
	- [[Preemptive Scheduling]]
- [[Scheduling Algorithm]]
	- [[First-Come, First-Served Scheduling]]
	- [[Shortest Job First Scheduling]]
	- [[Priority Scheduling]]
	- [[Round Robin Scheduling]]
	- [[Multilevel Queue Scheduling]]
	- [[Multilevel Feedback Queue Scheduling]]

---

# Reference

Operating System Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.