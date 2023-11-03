Tag: #Database 
Previous: [[Database]]
Link: 

[TOC]

---

When combining two tables, there is repetition of information. For example, the following figure shows the combination of `instructor` table and `department` table. (<u>1</u>)

![[Pasted image 20231103145215.png]]

In real case scenario, you will get the combined one, and develop a database the store the decomposed one. (<u>1</u>)

If you use the combined one directly in your database, there will be several issues: (<u>1</u>)

- [[Intersection Anomaly in Unnormalized Issues|Intersection Anomaly]]
- [[Deletion Anomaly in Unnormalized Issues|Deletion Anomaly]]
- [[Update Anomaly in Unnormalized Issues|Update Anomaly]]

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 7: Normalization.” NYCU ED117[GF], November 2, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.