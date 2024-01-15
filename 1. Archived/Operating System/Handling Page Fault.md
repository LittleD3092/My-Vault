Tag: #operating-system 
Previous: [[Demand Paging]]
Link: 

[TOC]

---

Figure below shows the steps of page fault: (<u>1</u>)

![[Pasted image 20231223210155.png]]

1. A load operation consults the page table.
2. Because of the invalid bit, page fault is triggered and the process is trapped.
3. The operating system finds the frame in the disk.
4. The missing page is brought to the physical memory.
5. The valid-invalid bit is flipped to valid.
6. The process is resumed.

In the steps above, 1 and 2 are handled by the [[Memory Management Unit|memory management unit]], and steps 3~6 are handled by the operating system. (<u>1</u>)

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.