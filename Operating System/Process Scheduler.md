Tag: #operating-system 
Previous: [[Process Scheduling]]
Link: 

[TOC]

---

- Operating systems must select processes from these queues in some fashion.
- The selection process is carried out by the appropriate **scheduler**.

Often, there are more processes submitted than can be executed immediately. The processes are spooled to a mass-storage device.

To select processes from different places, there are two schedulers:

|                        | Long-term Scheduler                                                                                                           | Short-term Scheduler                                        |
| ---------------------- | ----------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| Alias                  |                                                                                                                               | Also called **CPU scheduler**.                              |
| Function               | Selects processes from the mass-storage device, and loads them into memory. <br> Controls the **degree of multiprogramming**. | Selects from among the processes that are ready to execute. |
| Frequency of Execution | If the **degree of multiprogramming** is stable, the scheduler is invoked only when a process leaves the system.              | At least once every 100 milliseconds.                       |

- **Degree of Multiprogramming**: The number of processes in the memory.

# Long-term Scheduler

- It is important that the long-term scheduler select a good **process mix** of **I/O-bound process** and **CPU-bound process**.

| I/O-bound process           | CPU-bound process                   |
| --------------------------- | ----------------------------------- |
| Spends more time during I/O | Spends more time doing computations | 

- If all processes are I/O bound, the ready queue will almost always be empty. The short-term scheduler will have little to do.
- If all processes are CPU bound, the I/O waiting queue will almost always be empty. Devices will go unused.

# Medium-term Scheduler

- Some operating systems may use **medium-term scheduler**, which is an intermediate level of scheduling.
- It uses a scheme called [[Swap|swapping]].

![[Pasted image 20230628160302.png|400]]

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.