Tag: #operating-system 
Previous: [[Page Table]]
Link: 

[TOC]

---

If we store the whole page table, the space it uses will be large. 

Therefore, we use a hierarchical structure to store page table, which divides the page table into pieces, and only allocate each piece on demand.

- Pros: Page tables need not to be contiguous, and need not all present in memory.
- Cons: Multiple memory accesses if [[Translation Look-Aside Buffer for Paging|TLB]] miss happens.

# Example

The following page table is stored by a two-level hierarchy structure. Assume that each level has $2^{10}$ entries.

![[Pasted image 20231118161546.png|400]]

Steps to consult the page table:

1. First 10 bits is used to consult the outer page table.
2. The following 10 bits is used to consult the page table pointed by outer page table.
3. Access the memory with the frame number.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management, part 2.” NYCU EC122[GF], November 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.