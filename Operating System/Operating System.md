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

- [[Simple Structure of Operating System|Simple Structure]]
- [[Layered Approach of Operating System|Layered Approach]]
- [[Microkernel of Operating System|Microkernel]]
- [[Modules of Operating System|Modules]]
- [[Hybrid Operating System|Hybrid]]

## Debugging

- [[Debugging Operating System|Debugging]]

# Chapter 3: Process

A process can be thought of as a program in execution.

> [[Process]]

# Chapter 4: Threads

> [[Threads]]

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

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.
- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 5, part 2.” NYCU EC122[GF], October 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.