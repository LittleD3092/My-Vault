Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

- Note: debugging can also include **performance tuning**, by removing processing **bottlenecks**.

# Failure Analysis

For user processes:

- If a process fails, most operating systems write the error information to a **log file**.
- The operating system can also take a **core dump** and store it in a file.
	- **Core dump**: A capture of the memory of the process.

For operating system kernels:

- A failure in the kernel is called a **crash**.
- When a crash happens:
	- Error information is saved to a log file.
	- Memory state is saved to a **crash dump**.

# Performance Tuning

- The operating system produces **trace listings** of system behavior.
	- Interesting events are logged with their time and important parameters.
	- The trace listings are written to a file.

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.