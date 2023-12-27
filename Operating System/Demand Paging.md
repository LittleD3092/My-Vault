Tag: #operating-system 
Previous: [[Virtual Memory]]
Link: 

[TOC]

---

Demand paging is a technique that **bring a page to memory only when it is needed**. If the page is not needed, it will be stored in a **secondary storage**. (<u>1</u>)

This technique has following pros: (<u>1</u>)

- Less memory is needed.
- Faster response.
- More users and processes can run.
- Less I/O needed, since only a portion of a process is loaded.

When a page is needed, one of the following 2 cases will happen: (<u>1</u>)

- Page is in memory: Normally read it.
- Page is not in memory: A page fault is triggered and the frame is brought to memory.

Related topics: 

- [[Valid-Invalid Bit of Page Table]]
- [[Handling Page Fault]]
- [[Effective Access Time of Demand Paging]]
- [[Page Replacement]]
	- [[Victim Frame]]
	- [[Dirty Bit of Page Table]]
	- [[Page Replacement Policy]]
		- [[FIFO Page Replacement]]
		- [[Optimal Page Replacement]]
		- [[Least-Recently Used Page Replacement]]

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.