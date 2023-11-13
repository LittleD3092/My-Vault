Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

Paging is a technique to solve [[External Fragmentation|external fragmentation]]. (<u>1</u>)

Paging treats the physically fragmented free spaces logically contiguous, by using [[Frame in Paging|frame]] and [[Page in Paging|page]]. (<u>1</u>)

- [[External Fragmentation]]
	- [[Compaction for Solving External Fragmentation]]
- [[Frame in Paging]]
- [[Page in Paging]]
- [[Variables for Paging]]
- [[Implementation for Paging]]
	- [[Translation Look-Aside Buffer for Paging]]

# Example

To show how the paging technique works, we use the following example: (<u>1</u>)

![[Pasted image 20231110164721.png|400]]

Each [[Page in Paging|page]] is mapped to a [[Frame in Paging|frame]] by the page table. To access the frame, the following steps are done: (<u>1</u>)

1. Program accesses the logical memory.
2. Logical memory consults the page table for the corresponding [[Frame in Paging|frame]].
3. The [[Frame in Paging|frame]] is accessed.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management.” Asynchronous Online Course, November 8, 2023. https://drive.google.com/drive/folders/1b9_faOAujMVFTuq1hZDs0wBWwdN5JTj3.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.