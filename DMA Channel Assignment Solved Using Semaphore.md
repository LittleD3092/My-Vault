Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

A DMA controller supports 4 channels of data transfer. How to assign the channels to the processes?

The problem can be solved by using a semaphore `S` for preventing more than 4 channels being assigned. And a semaphore `T` for protecting the data structure `c[4]`, which indicates which channel isn't used.

```cpp
S = 4; T = 1; c[4] = {F, F, F, F};
proc()
{
	wait(S);
	wait(T);
	// pick one unused channel of c[4]
	// setup DMA transfer
	signal(T);
	// start DMA
	// wait for DMA completion
	signal(S);
}
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.