Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

There are many things to consider when we schedule multiple processors. Is there a queue global or each processor gets a queue? Do we give each processor a separate memory?

Depending on the questions above, 4 **types of scheduling** can appear:

- Global queue or separate queue:
	- [[Partitioned Scheduling]]
	- [[Global Scheduling]]
- Separate memory or a big memory connected to each processor by bus:
	- [[Symmetric Multiprocessing]]
	- [[Non-Uniform Memory Access]]

There are also 2 properties that we need to consider:

- [[Processor Affinity]]
- [[Load Balancing]]
	- [[Push Migration]]
	- [[Pull Migration]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 5, part 2.” NYCU EC122[GF], October 14, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.