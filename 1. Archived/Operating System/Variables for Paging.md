Tag: #operating-system 
Previous: [[Paging]]
Link: 

[TOC]

---

The paging technique contains 3 variables:

- $p$: Page number.
- $d$: Displacement of the data in a [[Page in Paging|page]] (or [[Frame in Paging|frame]]).
- $f$: Frame number.

![[Pasted image 20231110165034.png]]

The steps of paging:

1. CPU generates a page number $p$ and displacement $d$.
2. The page number $p$ is passed to the page table to find frame number $f$.
3. Frame number $f$ and displacement $d$ is passed to physical memory to find the address $f + d$.

# Example

![[Pasted image 20231110165456.png|]]

How many bits are required to represent:

1. The page number.
2. The frame number.
3. The displacement.
4. A logical address.
5. A physical address.
6. A page-table entry.

---

1. The page number:
There are 4 pages, therefore 2 bits need to be used to represent maximum page number `0b11`.
2. The frame number:
There are 8 frames, therefore 3 bits.
3. The displacement:
Each frame/page has 4 bytes, therefore 2 bits.
4. A logical address:
$$p + d = 4$$
5. A physical address:
$$f + d = 5$$
6. A page-table entry:
$$p + f = 5$$

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 8: Memory Management.” Asynchronous Online Course, November 8, 2023. https://drive.google.com/drive/folders/1b9_faOAujMVFTuq1hZDs0wBWwdN5JTj3.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.