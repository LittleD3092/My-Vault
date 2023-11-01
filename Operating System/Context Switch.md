Tag: #operating-system 
Previous: [[Process Scheduling]]
Link: 

[TOC]

---

Sometimes, interrupt occurs, and the operating system need to change a CPU from its current task to run a kernel routine. When interrupt occurs, the system needs to save the current **context** of the process so it can be restored when the routine is done.

- The context is represented in [[#Process Control Block|PCB]].
- The task of switching jobs is called **context switch**.
- The time of context switch depends on hardware, and should have a speed of few milliseconds.

The steps of context switch:

1. 

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.