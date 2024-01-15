Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

Jack and Rose are going to watch movie together, and they are meeting at the front of the theater. If someone arrived first, he or she needs to wait for the other person.

This can be solved using two semaphores, indicating who arrived.

```cpp
R = 0; J = 0;
jack()
{
	signal(J);
	wait(R);
	// watch movie
}
rose()
{
	signal(R);
	wait(J);
	// watch movie
}
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 2.” NYCU EC122[GF], October 20, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.