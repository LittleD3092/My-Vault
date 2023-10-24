Tag: #Database 
Previous: [[Entity-Relational Model]]
Link: [[Relationship Set]]

[TOC]

---

Based on the mapping of [[Relationship Set|relationship set]], we can get 3 categories:

| Type                      | Representation                       |
| ------------------------- | ------------------------------------ |
| One-to-one Relationship   | ![[Pasted image 20231024135727.png]] |
| One-to-many Relationship  | ![[Pasted image 20231024135925.png]] |
| Many-to-many Relationship | ![[Pasted image 20231024140120.png]] |

For more complex constraints, we use "$a..b$" to represent between $a$ and $b$ (inclusive).

![[Pasted image 20231024140510.png]]

If every entity in the entity set must participates in **at least one** relationship, we call it **total participation**. If not, we call it **partial participation**. We use double line and single line to represent this:

![[Pasted image 20231024140721.png]]

---

# Reference

- Tseng, Yi-Ju. “Chapter 6: Entity-Relational Model.” NYCU ED117[GF], October 12, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.