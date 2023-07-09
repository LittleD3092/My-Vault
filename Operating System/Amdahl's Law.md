Tag: #operating-system 
Previous: [[Threads]]
Link: 

[TOC]

---

Amdahl's Law is a formula that identifies potential performance gains from adding additional computing cores to an application that has both serial and parallel components.

$$\text{speedup} \leq \frac{1}{S + \frac{1 - S}{N}}$$

- $S$: The portion of the application that must be performed serially.
- $N$: The number of processing cores on a system.

> Note: When $N$ approaches infinity, the speedup converges to $1/S$.

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.