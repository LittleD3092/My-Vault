Tag: #operating-system #list 
Previous: 
Link: 

[TOC]

---

- Provide an environment for users to execute programs in a **convenient** and **efficient** way.
- A program that manages computer hardware, as a **resource allocator**.

The graph below shows the components of a computer system:

![[Pasted image 20230618134059.png|400]]

As above figure shows, a computer system can be divided into four components.

- Hardware.
	- Central processing unit (CPU).
	- Memory.
	- Input/output (I/O) device.
- Operating system.
- Application programs.
- Users.

# Computer System Operation

For a computer to start running, it goes through the following steps:

1. An initial program, **bootstrap program** is run.
	- It is supposed to be simple.
	- It is stored in read-only memory (ROM) or electrically erasable programmable read-only memory (EEPROM).
	- It is known by the general term **firmware**.
	- The bootstrap program locate the operating-system **kernel** and load it into memory.
2. The kernel starts services.
	- Some services are known as **system processes**, or **system daemons**.
3. The system is booted.

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.