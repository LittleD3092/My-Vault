Tag: #operating-system 
Previous: [[CPU Scheduling]]
Link: 

[TOC]

---

CPU scheduler selects from the processes in the memory that is ready.

CPU scheduler selects when:

- When current process switch from **running to waiting**.
- When current process switch from **running to ready**. (Receive time interrupt. For time sharing system only.)
- When queue process switch from **waiting to ready**.
- When current process **terminates**.

There are many algorithms for CPU scheduler:

- [[Cooperative Scheduling]]
- [[Preemptive Scheduling]]

---

# Reference

Operating System Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.