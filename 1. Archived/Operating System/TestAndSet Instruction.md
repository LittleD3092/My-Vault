Tag: #operating-system 
Previous: [[Atomic Instruction for Process Synchronization]]
Link: 

[TOC]

---

TestAndSet is an instruction that act like "**lock**". By using this instruction, you set a variable and get its original value.

The implementation might look like the code below. Be aware that the code below is its effect, not actual implementation.

```cpp
bool TestAndSet (bool* target)
{
	bool rv = *target;
	*target = TRUE; // lock it
	return rv; // return whether locked before operation
}
```

The [[Critical Section Problem|critical section problem]] can be solved like this:

```cpp
do {
	while ( TestAndSet ( &lock ) )
		; // do nothing
	// critical section
	lock = FALSE;
	// remainder section
} while ( TRUE );
```

---

# Reference

- 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization.” NYCU EC122[GF], October 18, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.