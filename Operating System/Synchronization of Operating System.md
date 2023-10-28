Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

When processes work together on the same memory space, **data race** happens. We need to solve this problem.

Following list is some solutions or concepts:

- [[Critical Section Problem]]
	- [[Mutual Exclusion of Critical Section|Mutual Exclusion]]
	- [[Progress of Critical Section|Progress]]
	- [[Bounded Waiting of Critical Section|Bounded Waiting]]
- [[Hardware Approach to Process Synchronization|Hardware Approach]]
	- [[Interrupt Disabling for Process Synchronization|Interrupt Disabling]]
	- [[Atomic Instruction for Process Synchronization|Atomic Instruction]]
		- [[TestAndSet Instruction]]
		- [[Swap Instruction]]
	- [[Semaphores for Process Synchronization|Semaphores]]
		- [[Mutex Lock]]
		- [[Sequencing or Event]]
		- [[Capacity Control]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.