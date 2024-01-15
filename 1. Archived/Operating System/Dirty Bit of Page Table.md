Tag: #operating-system 
Previous: [[Page Replacement]]
Link: 

[TOC]

---

To replace the page, the victim page must be written back to the disk (backing store). To save this written back time, we use dirty bit to indicate modified frame. **We only need to written the modified pages to the disk**.

---

# Reference

1. 張立平, “Introduction to Operating Systems, Chapter 9: Virtual Memory,” NYCU EC122[GF], Nov. 22, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.