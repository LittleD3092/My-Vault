Tag: #operating-system 
Previous: [[Process]]
Link: 

[TOC]

---

- Cooperating processes require a mechanism called **Interprocess Communication (IPC)**.

There are two fundamental models for IPC:

| Shared Memory                                                                            | Message Passing                                                                                            |
| ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| A section of memory is shared by multiple processes.                                     | Messages are passed between processes                                                                      |
| <ul> <li> Faster than message passing. <li> No assistance from kernel is required. </ul> | <ul> <li> Useful for exchanging small amount of data. <li> Easy to implement for distributed system. </ul> |

![[Pasted image 20230705143112.png|300]]

> Note: Most operating systems implement both.

- [[Shared-Memory Systems]]
- [[Message-Passing Systems]]

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.