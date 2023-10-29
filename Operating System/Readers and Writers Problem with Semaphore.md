Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

There are multiple writers and multiple readers. Writers can **read and write**, and readers can only **read** (<u>1</u>). How to prevent multiple writers write to a file?

We can group readers together, and each writer has a group, like so (<u>1</u>):

```
+------+   +---+           +---+
| RRR  |   | W |   +---+   | W |
|  RRR |   +---+   | W |   +---+
+------+           +---+

No pairs of circles can access data the same time.
```

The pseudo code of the solution (<u>1</u>):

```cpp
// The structure of a writer process
do {
	wait(wrt);
	// writing is performed
	signal(wrt);
} while (true);

// ---

// The structure of a reader process
do {
	wait(mutex);
	readcount++;
	if(readercount == 1) wait(wrt);
	signal(mutex);
	
	// reading is performed

	wait(mutex);
	readcount--;
	if(readcount == 0) signal(wrt);
	signal(mutex);
} while (true);
```

- `wrt`: Initialized to `1`. Its purpose is to avoid 2 groups access the data simultaneously.
- `mutex`: Initialized to `1`. Its purpose is to protect `readercount`.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 4.” NYCU EC122[GF], October 25, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.