Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

This problem is about a fixed amount of processes can enter. It can be solved by setting **initial value of semaphore** $= \text{capacity}$.

The solution using semaphore to capacity control is similar to [[Critical Section Problem|critical section problem]], but in this solution we allow multiple processes enter:

```cpp
P_i, P_j, P_k, ...
{
	...
	wait(sem);
	...
	signal(sem);
	...
}
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.