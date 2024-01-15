Tag: #operating-system 
Previous: [[Paging]]
Link: 

[TOC]

---

- Each process has its page table, and also each process has its logical memory. (<u>1</u>)
- The page table is kept in main memory. This means that there will be 2 memory access for each data/instruction access. The delay can be accelerated by [[Translation Look-Aside Buffer for Paging|translation look-aside buffer]]. (<u>1</u>)

Related topics:

- [[Translation Look-Aside Buffer for Paging]]

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management.” Asynchronous Online Course, November 8, 2023. https://drive.google.com/drive/folders/1b9_faOAujMVFTuq1hZDs0wBWwdN5JTj3.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.