Tag: #operating-system 
Previous: [[Process]]
Link: 

[TOC]

---

- The [[#Process Scheduler|process scheduler]] selects an available process for program execution.

Operating systems use queues to schedule processes.

- As processes enter the system, they are put into a **job queue**.
- The processes that are stored in main memory and ready to execute are in a list called **ready queue**.
- The list of processes waiting for a particular I/O device is called a **device queue**.
- The queues are stored in [[Linked List|linked lists]].

> A process migrates among the various scheduling queues throughout its lifetime.

![[Pasted image 20230627140155.png|400]]

A representation of process scheduling is a **queueing diagram**:

![[Pasted image 20230627140336.png|400]]

- Each rectangular box represents a queue.
- The circles represent the resources that serve the queues.
- The arrows indicate the flow of processes in the system.
- A new process is initially put in the ready queue, waiting to be selected for execution, or **dispatched**.

Concepts related:

- [[Context Switch]]
- [[Process Scheduler]]

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.