Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

Round robin allocates CPU time to each process like so:

- Each process gets a **time quantum** $q$.
- After the process uses all its execute time $q$, it is **placed at the end** of ready queue.

This method provides a **responsive** system. Each process is **guaranteed to have CPU time** in most $(n - 1)q$ time of waiting ($n$ processes in waiting queue).

There are few remarks about setting the time quantum $q$:

- $q$ very **big**: This method becomes **[[First-Come, First-Served Scheduling]]**, because processes never run out of CPU time.
- $q$ very **small**: The **overhead** of switching processes is huge.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.