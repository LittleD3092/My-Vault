Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

Linux introduces hierarchical scheduling domain as a solution to schedule process among both the **physical CPU** and the **logical CPU**:

![[Pasted image 20231024213942.png|500]]

The procedure contains 2 steps:

1. Firstly, evenly distribute processes among **physical CPU**.
2. In each CPU, evenly distribute processes among **logical CPUs**.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5, part 2.” NYCU EC122[GF], October 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.