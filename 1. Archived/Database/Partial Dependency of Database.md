Tag: #Database 
Previous: [[Second Normal Form]]
Link: 

[TOC]

---

Partial dependency means that one element of a composite candidate key can be used to identify a non-prime attribute. In short, $AX$ is the composite candidate key, $A \rightarrow B$, and $B$ is non-prime attribute.

For example:

![[Pasted image 20231120134056.png]]

- `CourseID` is $A$.
- `StudentID` is $X$.
- `InstructorID` is $B$.

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 7: Normalization.” NYCU ED117[GF], November 16, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.