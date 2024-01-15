Tag: #operating-system 
Previous: [[Atomic Instruction for Process Synchronization]]
Link: 

[TOC]

---

The swap instruction (it's atomic) has the below effect:

```cpp
void Swap (bool *a, bool *b)
{
	bool temp = *a;
	*a = *b;
	*b = temp;
}
```

The solution to [[Critical Section Problem|critical section problem]]:

```cpp
do {
	key = TRUE;
	while (key == TRUE) // keep attempt to lock
		Swap(&lock, &key);

	// critical section

	lock = FALSE;

	// remainder section
} while (TRUE);
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.