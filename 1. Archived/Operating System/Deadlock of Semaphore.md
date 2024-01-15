Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

Deadlock means that two or more processes are waiting forever. (<u>1</u>)

For example, two processes with different order of semaphore implementation: (<u>1</u>)

```cpp
// Process 0
wait(S);
wait(Q);
// ...
signal(Q);
signal(S);

// ---

// Process 1
wait(Q);
wait(S):
// ...
signal(S);
signal(Q);
```

The code above might block, because process 0 may lock `S` and process 1 may lock `Q`. Then, both processes will wait for each other, causing the deadlock. (<u>1</u>)

- [[Conditions of Deadlock]]
- [[Resource Allocation Graph]]

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.