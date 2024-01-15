Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Cartesian products $\times$ allows us to combine two relations, although we often use [[Join Operation|join operation]] to filter out the [[Tuple|tuple]] that we don't need. 

The Cartesian product will get all possible combinations of [[Tuple|tuple]].

For example, the Cartesian product of the two tables:

![[Pasted image 20231011215836.png]]

will yield a table like this:

![[Pasted image 20231011215904.png]]

# Join Operation

[[Select Operation|Select operation]] is often used with Cartesian product. For example:

$$\sigma_{\rm instructor.ID = teaches.ID}(\rm instructor \times teaches)$$

remove IDs that doesn't match.

This select and product combo is known as [[Join Operation]].

---

# Reference

Database Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.