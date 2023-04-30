Tag: #computer-organization 
Previous: 
Link: 

[TOC]

---

- To know when a task is finished writing so that it is safe for another to read, the tasks need to synchronize.
- [[Data Race]]: The results change depend on how events happen to occur.
	- To prevent [[Data Race]], we use a pair of instructions: [[Load Linked]] and [[Store Conditional]].
		- [[Load Linked]]: Lock the register. Returns te value in register.
		- [[Store Conditional]]: Store value, and unlock the register. Return 0 if store fails.
	- The pair of instructions are used in sequence.

An example to store `1` into address saved in `$s0`:

```s
again: addi $t0, $zero, 1     # $t0 = 1
       ll   $t1, 0($s1)       # $t1 = *($s1)
       sc   $t0, 0($s1)       # $t0, *($s1) = success(), $t0
       beq  $t0, $zero, again # if(fails) goto again
       add  $s4, $zero, $t1   # $s4 = $t1
```

- [[Load Linked]] and [[Store Conditional]] instructions can be used to build other synchronization primitives, such as:
	- Atomic compare and swap.
	- Atomic fetch-and-increment

> Caution: The instructions between [[Load Linked]] and [[Store Conditional]] should be small to prevent other's [[Store Conditional]] to fail frequently.

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.