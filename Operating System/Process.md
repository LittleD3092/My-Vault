Tag: #operating-system #list 
Previous: [[Operating System]]
Link: 

[TOC]

---

- A **process** is a program in execution.
- Traditionally, a process contained only a single **thread**.
- Modern operating systems now support processes that have multiple threads.

A process contains:

- **Text section**: Executable binaries.
- **Program counter and registers**: The current activity, represented by value.
- **Stack**: Contains temporary data.
- **Data section**: Global variables.
- **Heap**: Memory that is dynamically allocated during run time.

> Note: A program by itself is not a process.
> A program is a **passive** entity, such as a file containing instructions.
> A process is an **active** entity, with a program counter specifying the next instruction to execute.

- [[Process State]]
- [[Process Control Block]]
- [[Process Scheduling]]
	- [[Context Switch]]
	- [[Process Scheduler]]
- [[Operations on Processes]]
- [[Process Synchronization]]
- [[Zombie Process]]
- [[Orphaned Process]]

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.