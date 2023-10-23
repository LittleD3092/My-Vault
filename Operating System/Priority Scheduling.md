Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

Priority scheduling gives a **priority number** (usually an integer) to each process. The [[CPU Scheduler|CPU scheduler]] chooses the process with the most priority.

Note that there might be **starvation** (low priority processes never get executed). 

There is a solution to this problem called **aging**. As time progresses, the [[CPU Scheduler|CPU scheduler]] can **increase the priority number**, and the process starving can get CPU time eventually.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.