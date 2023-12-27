Tag: #operating-system 
Previous: [[Demand Paging]]
Link: 

[TOC]

---

When a page fault is triggered, the frame is brought into memory. What if the memory is already full?

We must determine which page should remain in main memory, and "replace" the frame with more demanding page. (<u>1</u>)

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