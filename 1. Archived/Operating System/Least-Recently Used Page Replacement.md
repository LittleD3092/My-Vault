Tag: #operating-system 
Previous: [[Page Replacement Policy]]
Link: 

[TOC]

---

![[Pasted image 20240115131132.png]]

Least-recently used algorithms choose the page that is least recently used and replace them. (<u>1</u>)

![[Pasted image 20240115131305.png|450]]

An implementation contains two components:

- **Hash table**: Take a page number as an index, save the address to the node in the list.
- **Linked list**: Keep track of the order of lastly used. A node at the tail (or head) will be chosen as a **victim**.

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.