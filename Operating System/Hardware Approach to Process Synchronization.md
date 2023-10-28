Tag: #operating-system 
Previous: [[Synchronization of Operating System]]
Link: [[Critical Section Problem]]

[TOC]

---

In [[Critical Section Problem|critical section problem]], we mentioned that critical sections must be **atomic**. This is hard without hardware help.

Following list shows tools or methods that hardware provides for us to solve [[Critical Section Problem|critical section problem]].

- [[Interrupt Disabling for Process Synchronization|Interrupt Disabling]]
- [[Atomic Instruction for Process Synchronization|Atomic Instruction]]
	- [[TestAndSet Instruction]]
	- [[Swap Instruction]]
- [[Semaphores for Process Synchronization|Semaphores]]
	- [[Mutex Lock]]
	- [[Sequencing or Event]]
	- [[Capacity Control]]
	- [[Jack and Rose Watch Movie Solved Using Semaphores|Jack and Rose Watch Movie]]
	- [[DMA Channel Assignment Solved Using Semaphore|DMA Channel Assignment]]
	- [[Deadlock of Semaphore|Deadlock]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.