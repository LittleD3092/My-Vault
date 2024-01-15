Tag: #Database 
Previous: [[Normalization Process of Database]]
Link: 

[TOC]

---

Boyce-Codd normal form is also known as BCNF.

BCNF is used to further normalize [[Third Normal Form|3NF]] and reduce redundancy. For all functional dependencies $\alpha \rightarrow \beta$ in BCNF, at least one of the following holds:

- $\alpha \rightarrow \beta$ is trivial ($\beta \subseteq \alpha$).
- $\alpha$ is a superkey.

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 7: Normalization.” NYCU ED117[GF], November 16, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.