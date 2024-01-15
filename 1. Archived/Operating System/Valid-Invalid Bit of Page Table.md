Tag: #operating-system 
Previous: [[Demand Paging]]
Link: 

[TOC]

---

To implement demand paging, a valid-invalid bit is included in the page table. It is used to **keep track of whether the frame of requested page is in memory**.

- $1$ for in memory, $0$ for not in memory.
- If valid-invalid bit in page table entry is $0$, **page fault** is triggered.

![[Pasted image 20231223205929.png]]

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.