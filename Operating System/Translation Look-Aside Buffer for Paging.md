Tag: #operating-system 
Previous: [[Implementation for Paging]]
Link: 

[TOC]

---

The translation look-aside buffer can be used to solve the 2-memory-access problem with [[Paging|paging]]. (<u>1</u>)

The figure below shows that CPU first consults the translation look-aside buffer for cache, then if miss, it consults the actual page table. (<u>1</u>)

![[Pasted image 20231110171109.png]]

- [[Effective Access Time of Translation Look-Aside Buffer]]

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management.” Asynchronous Online Course, November 8, 2023. https://drive.google.com/drive/folders/1b9_faOAujMVFTuq1hZDs0wBWwdN5JTj3.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.