Tag: #Database 
Previous: [[Relational Database]]
Link: 

[TOC]

---

Keys are a set of [[Attribute|attributes]] used to identify [[Tuple|tuples]]. There are 4 kinds of keys, but the last two are the most important ones.

- [[Superkey]]: A **set** of attributes that is sufficient to **identify** a unique tuple.
	- Ex: `{ID}` and `{ID, name}` are both superkey.
- [[Candidate Key]]: Chosen from [[Superkey|superkeys]] that is **minimal**.
	- Ex: `{ID}`. Note that `{ID, name}` is not minimal.
- [[Primary Key]]: One of the [[Candidate Key|candidate keys]] can be **chosen** to be primary.
- [[Foreign Key]]: Attributes that **point to** another table. The values of foreign key **must exist** in the pointed table.

---

# Reference

Database Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.