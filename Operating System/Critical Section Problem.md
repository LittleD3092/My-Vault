Tag: #operating-system 
Previous: [[Synchronization of Operating System]]
Link: 

[TOC]

---

This problem mark **instructions that modify memories** critical sections, like this:

```cpp
do {
	// entry section
		// critical section

	// exit section
		// remainder section
} while (TRUE);
```

Because operating systems may **context switch** in the critical section, we need to make critical sections **atomic**, so that context switch will not happen in the middle of critical section.

In order to solve the critical section problems, 3 rules are introduced:

- [[Mutual Exclusion of Critical Section|Mutual Exclusion]]
- [[Progress of Critical Section|Progress]]
- [[Bounded Waiting of Critical Section|Bounded Waiting]]

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.