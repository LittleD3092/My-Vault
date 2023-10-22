Tag: #operating-system 
Previous: [[CPU Scheduler]]
Link: 

[TOC]

---

Contains only two conditions from [[CPU Scheduler]], cooperative scheduling selects when:

- When current process switch from **running to waiting**.
- When current process **terminates**.

This method is **easy to implement**. 

However, it requires a process **voluntarily gives up the CPU**, and an ill-behaved process can take over the system.

---

# Reference

Operating System Course

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.