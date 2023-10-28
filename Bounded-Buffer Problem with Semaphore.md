Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

Bounded-buffer problem is about a reader and a sender accessing the same memory. The solution to this problem uses 3 semaphores:

- `mutex`: To protect the buffer. Initial value is `1`.
- `full`: Block when no items in the buffer. Initial value is `0`.
- `empty`: Block when no free slots in the buffer. Initial value is `N` (number of available slots).

```cpp
// producer process
do {
	// produce an item
	wait(empty);
	wait(mutex);
	// add the item to the buffer
	signal(mutex);
	signal(full);
} while(true);

// ---

// consumer process
do {
	wait(full);
	wait(mutex);
	// remove an item from buffer
	signal(mutex);
	signal(empty);
	// consume the removed item
} while(true);
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 3.” NYCU EC122[GF], October 21, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.