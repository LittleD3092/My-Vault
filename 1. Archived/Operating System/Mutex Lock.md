Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: [[Critical Section Problem]]

[TOC]

---

Mutex lock allows only **one process enter at a time**. This can be done by setting the **initial value of semaphore** $=1$. This is equivalent to [[Critical Section Problem|critical section problem]].

Below is the [[Critical Section Problem|critical section problem]] solved using [[Semaphores for Process Synchronization|semaphore]].

```cpp
do {
	waiting(mutex);
	// critical section
	signal(mutex);
	// remainder section
} while (TRUE);
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.