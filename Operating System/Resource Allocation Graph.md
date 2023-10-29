Tag: #operating-system 
Previous: [[Deadlock of Semaphore]]
Link: 

[TOC]

---

Resource allocation graph is a representation of resources and processes. Here are some components: (<u>1</u>)

- **Resource**: Represented by boxes.
- **Processes**: Represented by circles.
- **Instances**: Represented by dots. Refers the number of processes can access the resource.
- **Holding/Requesting**: An arrow pointed from an instance is holding; an arrow pointed to a resource is requesting.

The following graph is a **deadlocked** graph: (<u>1</u>)

![[Pasted image 20231029213810.png|200]]

The following graph is **not** a deadlocked graph: (<u>1</u>)

![[Pasted image 20231029213953.png|200]]

Note that deadlocked graph always have a cycle, but a cycled graph isn't always deadlocked. (<u>1</u>)

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 7: Deadlocks.” NYCU EC122[GF], October 25, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.