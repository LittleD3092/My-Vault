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
		- [[Jack and Rose Watch Movie Solved Using Semaphores|Jack and Rose Watch Movie]]
		- [[DMA Channel Assignment Solved Using Semaphore|DMA Channel Assignment]]
		- [[Bounded-Buffer Problem with Semaphore|Bounded-Buffer Problem]]
		- [[Readers and Writers Problem with Semaphore|Readers and Writers Problem]]
		- [[Dining-Philosophers Problem with Semaphore|Dining-Philosophers Problem]]
		- [[Sleeping Barber Problem with Semaphore|Sleeping Barber Problem]]
		- [[Deadlock of Semaphore|Deadlock]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 3.” NYCU EC122[GF], October 21, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.