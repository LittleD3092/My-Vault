Tag: #operating-system 
Previous: [[Demand Paging]]
Link: 

[TOC]

---

The performance of demand paging can be evaluated by the effective access time:

$$
\begin{array}{l}
{\rm EAT} &=& (1 - p) \cdot \text{memory access} + \\
&&p \cdot (\text{page fault overhead} + \text{swap page out} + \\ && \ \ \ \ \ \ \text{swap page in} + \text{restart overhead})
\end{array}
$$

- We can combine the [[Effective Access Time of Translation Look-Aside Buffer]] and calculate the EAT more accurately.
	- If TLB hit, only consider time of TLB.
	- If TLB miss and not a page fault, only consider time of TLB.
	- If TLB miss and page fault, consider time of both TLB and page fault.

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.