Tag: #operating-system #list 
Previous: [[Operating System]]
Link: 

[TOC]

---

- A thread is a basic unit of CPU utilization.
- It comprises:
	- A thread ID.
	- A program counter.
	- A register set.
	- A stack.

![[Pasted image 20230707150556.png|450]]

Benefits of multithreaded programming:

1. **Responsiveness**: The applications are all responsive to the user.
2. **Resource sharing**: Allows an application to have several different threads of activity within the same address space, like the figure above.
3. **Economy**: Allocating memory and resources for process creation is costly, but context switching is cheaper.
4. **Scalability**: For multiprocessor architecture, the threads can be run on different processing cores.

# Multicore Programming

| Parallelism                                             | Concurrency                                                             |
| ------------------------------------------------------- | ----------------------------------------------------------------------- |
| A system can perform more than one task simultaneously. | Supports more than one task by allowing all the tasks to make progress. | 

> Note: It is possible for a system to achieve concurrency without parallelism.

## Amdahl's Law

Amdahl's Law is a formula that identifies potential performance gains from adding additional computing cores.

> [[Amdahl's Law]]

## Types of Parallelism

There are two types of parallelism:

- [[Data Parallelism]]:
	- Distributing subsets of the same data across multiple cores and performing the same operation on each core.
	- *Example*:
		- Summing contents of an array of size $N$.
		- Thread $A$ could sum the elements $[0] \dots [N/2-1]$.
		- Thread $B$ could sum the elements $[N/2] \dots [N-1]$.
- [[Task Parallelism]]:
	- Distributing tasks (threads) across multiple computing cores.

# Multithreading Models

User threads are managed by kernel threads, and kernel threads are managed directly by the operating system.

To map the user threads to the kernel threads, we have three different ways:

| Many-to-One Model                                                                                                                                                                                                                                                           | One-to-One Model                                                                                                                                                                                                                               | Many-to-Many Model                                                                                                                                             |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ![[Pasted image 20230707153653.png]]                                                                                                                                                                                                                                        | ![[Pasted image 20230707154100.png]]                                                                                                                                                                                                           | ![[Pasted image 20230707154639.png]]                                                                                                                           |
| <ul><li>Maps many user-level threads to one kernel thread.<li>Only one thread can access the kernel at a time.<li>The entire process will block if a thread makes a blocking system call.<li>Con: Multiple threads are unable to run in parallel on multicore systems.</ul> | <ul><li>Maps each user thread to a kernel thread.<li>Provides more concurrency than the many-to-one model.<li>Con: Creating a user thread requires creating the corresponding kernel thread, and the overhead can burden the performance.</ul> | <ul><li>Multiplexes many user-level threads to a smaller or equal number of kernel threads. <li>Does not suffer from the cons of the previous two models.</ul> | 

# Implicit Threading

Transfer the creation and management of threading from application developers to compilers and run-time libraries.

> [[Implicit Threading]]

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.