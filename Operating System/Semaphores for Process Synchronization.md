Tag: #operating-system 
Previous: [[Hardware Approach to Process Synchronization]]
Link: 

[TOC]

---

Semaphores have following components:

- Semaphore `S`: An integer variable, initial value $\geq 0$.
- Two instruction:
	- `wait()`
	- `signal()`

The implementations of `wait()` and `signal()`:

```cpp
wait (S) {
	S--;
	if (S < 0) {
		// add this process to waiting queue
		block ();
	}
}

signal (S) {
	S++;
	if (S <= 0) {
		// remove a process P from the waiting queue
		wakeup (P);
	}
}
```

- `block()`: Put a process into sleep. A process in sleep does not consume CPU cycle.
- `wakeup(P)`: Wake up a process specified.

# Usages

Semaphores are useful, and they have many usages:

- [[Mutex Lock]]
- [[Sequencing or Event]]
- [[Capacity Control]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.