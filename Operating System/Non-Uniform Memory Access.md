Tag: #operating-system 
Previous: [[Multiple-Processor Scheduling]]
Link: 

[TOC]

---

| Symmetric Multiprocessing                     | [[Non-Uniform Memory Access]]        |
| --------------------------------------------- | ------------------------------------ |
| A big memory is connected to each CPU by bus. | Each processor has its own memory.   |
| ![[Pasted image 20231023181037.png]]          | ![[Pasted image 20231023181044.png]] | 

Note that both 2 methods have **program migration cost**, but the cost of [[Non-Uniform Memory Access|NUMA]] is significantly **bigger than SMP**.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.