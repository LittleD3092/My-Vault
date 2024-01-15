Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Project operations $\Pi$ are used to **select attributes** in the table.

$$\Pi_{A_1, \dots, A_k}(r)$$

- $A_1, \dots, A_k$: Attribute names.
- $r$: Relation (table) name.

For example:

![[Pasted image 20231011214432.png]]

Note that you can combine other [[Relational Algebra|relational algebra]]. For example:

$$\Pi_{\rm name}(\sigma_{\rm dept\_name = 'physics'}(\rm instructor))$$

will select the `name` of `instructors` that teaches `physics`.

---

# Reference

Database Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.