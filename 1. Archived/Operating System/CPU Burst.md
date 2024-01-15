Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

The CPU burst is **the simultaneous time** that a process need to use the CPU. This value is useful for [[CPU Scheduling]].

# Determine Length of Next CPU Burst

In practice, it is hard to determine the exact CPU burst. Therefore, there are ways of "**guessing**" it.

The function below uses the **previous CPU burst** and **previous guess** to determine the next CPU burst (guess).

$$\tau_{n + 1} = \alpha t_n + (1 - \alpha) \tau_n$$

- $t_n$: The previous actual CPU burst.
- $\tau_n$: The previous predicted value.
- $\alpha, 1 - \alpha$: The ratio that is often set to $0.5$.

![[Pasted image 20231023163701.png]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 5.” NCTU EC122[GF], October 11, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.