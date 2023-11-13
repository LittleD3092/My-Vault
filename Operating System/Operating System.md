Tag: #operating-system #list 
Previous: 
Link: 

[TOC]

---

# Chapter 1: Introduction

- [[Operating System Structure]]
	- [[Interrupt]]
	- [[Direct Memory Access]]
	- [[Synchronous and Asynchronous IO]]
	- [[Multi Programming]]

# Chapter 2: System Structures

## View of Operating System

We can view operating system based on 3 aspects:

- [[Operating System Services|Services]]
- [[Operating System Interfaces|Interfaces]]
	- [[System Call]]
- [[Operating System Components and Interconnections|Components and Interconnections]]
	- [[System Programs]]

## Structure

There are different kinds of structures. Some are divided into **modules**, some are not.

- [[Possible Operating System Structures]]
	- [[Simple Structure of Operating System|Simple Structure]]
	- [[Layered Approach of Operating System|Layered Approach]]
	- [[Microkernel of Operating System|Microkernel]]
	- [[Modules of Operating System|Modules]]
	- [[Hybrid Operating System|Hybrid]]
- [[User-Kernel Mode Separation]]
	- [[Kernel Mode]]
	- [[User Mode]]

## Debugging

- [[Debugging Operating System|Debugging]]

# Chapter 3: Process

A process can be thought of as a program in execution.

- [[Process]]
	- [[Process State]]
	- [[Process Control Block]]
	- [[Process Scheduling]]
		- [[Context Switch]]
		- [[Process Scheduler]]
	- [[Operations on Processes]]
	- [[Process Synchronization]]

# Chapter 4: Threads

- [[Threads]]

# Chapter 5: CPU Scheduling

- [[CPU Scheduling]]
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
- [[CPU Burst]]
- [[Multiple-Processor Scheduling]]
	- Scheduling categories:
		- [[Partitioned Scheduling]]
		- [[Global Scheduling]]
		- [[Symmetric Multiprocessing]]
		- [[Non-Uniform Memory Access]]
	- Properties:
		- [[Processor Affinity]]
		- [[Load Balancing]]
			- [[Push Migration]]
			- [[Pull Migration]]
- Multi-core and Multi-threading Processors
	- [[Multi-core Processor]]
	- [[Multi-thread Processor]]
	- [[Hierarchical Scheduling Domains]]
	- [[Light-Weight Process]]
		- [[Process Contention Scope]]
		- [[System Contention Scope]]

# Chapter 6: Synchronization

- [[Synchronization of Operating System|Synchronization]]
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

# Chapter 7: Deadlocks

- [[Deadlock of Semaphore|Deadlock]]
	- [[Conditions of Deadlock]]
	- [[Resource Allocation Graph]]

# Chapter 8: Memory Management

- [[Paging]]
	- [[External Fragmentation]]
		- [[Compaction for Solving External Fragmentation]]
	- [[Frame in Paging]]
	- [[Page in Paging]]
	- [[Variables for Paging]]
	- [[Implementation for Paging]]

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.
- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 5, part 2.” NYCU EC122[GF], October 14, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 3.” NYCU EC122[GF], October 21, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.