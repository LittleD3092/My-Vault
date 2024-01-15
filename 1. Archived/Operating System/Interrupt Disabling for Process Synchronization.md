Tag: #operating-system 
Previous: [[Hardware Approach to Process Synchronization]]
Link: 

[TOC]

---

If we disable the interrupt of CPU, we can **prevent context switch**, and may solve [[Critical Section Problem|critical section problem]]. But this method raises some problems.

The possible problems:

- For uni-processor system: Masking interrupt will prevent the running process from being preempted.
- For multiprocessor: Will not prevent other CPUs from entering a critical section.
- This interrupt disabling instruction must be privilege instruction (or will be dangerous), and user processes won't be able to use it.

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.