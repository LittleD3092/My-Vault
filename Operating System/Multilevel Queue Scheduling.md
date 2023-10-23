Tag: #operating-system 
Previous: [[Scheduling Algorithm]]
Link: 

[TOC]

---

In this scheduling, the only one queue in [[Round Robin Scheduling]] is separated into **multiple queues**:

![[Pasted image 20231023165323.png]]

The [[CPU Scheduler]] takes out **one process from each queue**. After time quantum $q$ (maybe set different for each queue) is reached, the process is put back to the queue.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.