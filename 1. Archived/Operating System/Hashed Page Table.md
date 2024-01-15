Tag: #operating-system 
Previous: [[Page Table]]
Link: 

[TOC]

---

This page table is a concept, and is not used directly. [[Inverted Page Table|Inverted page table]] uses this concept. (<u>1</u>)

Hashed page table uses a hash table as a page table: (<u>1</u>)

![[Pasted image 20231118162637.png]]

Because the hash function may hash into the same entry, each entry is a linked list. (<u>1</u>)

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management, part 2.” NYCU EC122[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.