Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

A graphical illustration to the dining-philosophers problem is illustrated below (<u>1</u>):

![[Pasted image 20231029204605.png|300]]

Each philosopher can only reach 2 chopsticks beside them. They need to get 2 chopsticks to start eating, otherwise they wait (<u>1</u>). How to avoid the [[Deadlock of Semaphore|deadlock]] in this case?

# Intuitive Solution

An **intuitive** (but wrong) solution is to grab chopsticks from left to right, code provided below (<u>1</u>):

```cpp
do {
	wait(chopstick[i]);
	wait(chopstick[(i + 1) % 5]);
	
	// eat

	signal(chopstick[i]);
	signal(chopstick[i + 1] % 5);

	//think
} while (true);
```

If each person takes one chopstick, they will be waiting for the other one forever (<u>1</u>).

# Solution

There are various ways to solve this (<u>1</u>):

1. Allow up to $N$ ($N < 5$) people to pick up chopsticks.
2. Pick up both chopsticks simultaneously (possible only if atomic instruction exists).
3. One person picks left chopstick first, and the rest people pick the right chopstick first.

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 4.” NYCU EC122[GF], October 25, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.