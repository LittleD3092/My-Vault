Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

This is a consumer-and-producer problem, or sorting events. This can be solved by setting **initial value of semaphore** $=0$.

An example of sorting events:

```cpp
// Process i
S_1;
signal(synch);

// ---

// Process j
wait(synch);
S_2;
```

The section $S_2$ will always be executed later than section $S_1$.

This framework can also be applied on a dispatcher-worker problem:

```cpp
// Process i, dispatcher
S_1;
signal(synch);

// ---

// Process j, worker 1
wait(synch);
S_2;

// ---

// Process k, worker 2
wait(synch);
S_2;
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.
- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.