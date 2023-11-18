Tag: #operating-system 
Previous: [[Page Table]]
Link: 

[TOC]

---

Because each process has its own page table, it may consume a lot of space. What if instead of mapping pages to frames, we map frames to pages? (<u>1</u>)

![[Pasted image 20231118162938.png|500]]

The page table is frame number indexed, therefore: (<u>1</u>)

- The page table will not have more entries than physical memory.
- The page table is used globally. (each process consults the same table)

The searching process is done by hash function, using `pid` and page number `p`.

> The `pid` is necessary because each process may have the same page number.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management, part 2.” NYCU EC122[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.