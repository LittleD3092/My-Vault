Tag: #operating-system 
Previous: [[Operating System]]
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

## Basics of Operating System

### Computer System Operation

For a computer to start running, it goes through the following steps:

1. An initial program, **bootstrap program** is run.
	- It is supposed to be simple.
	- It is stored in read-only memory (ROM) or electrically erasable programmable read-only memory (EEPROM).
	- It is known by the general term **firmware**.
	- The bootstrap program locate the operating-system **kernel** and load it into memory.
2. The kernel starts services.
	- Some services are known as **system processes**, or **system daemons**.
3. The system is booted.

### What Operating System Do

The following three functions are called "The Three Pillars".

- **Process management**:
	- Scheduling processes and threads on the CPUs.
	- Creating and deleting both user and system processes.
	- Suspending and resuming processes.
	- Providing mechanisms for process synchronization.
	- Providing mechanisms for process communication.
- **Memory management**:
	- Keeping track of which parts of memory are currently being used and who is using them.
	- Deciding which process and data to move into and out of memory.
	- Allocating and deallocating memory space as needed.
- **File management**:
	- Creating and deleting files.
	- Creating and deleting directories to organize files.
	- Supporting primitives for manipulating files and directories.
	- Mapping files onto secondary storage.
	- Backing up files on stable (nonvolatile) storage media.

## Interrupt

> [[Interrupt]]

## Direct Memory Access

> [[Direct Memory Access]]

## Synchronous I/O vs Asynchronous I/O

> [[Synchronous and Asynchronous IO]]

## Multi Programming

> [[Multi Programming]]

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.