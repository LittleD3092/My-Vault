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

# What Operating System Do

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

# Structures

We can view operating system based on 3 aspects:

- [[#Services]]
- [[#Interfaces]]
- [[#Components and Interconnections]]

## Services

![[Pasted image 20230623163107.png|500]]

Some services:

- **User Interface**: This can take several forms.
	- **Command-line Interface** (CLI): Text commands.
	- **Batch Interface**: The commands are saved as files, and the files are executed.
	- **Graphical User Interface** (GUI): A window system with a pointing device to select menus and buttons.
- **Program Execution**: Load the program into memory and run. The program must be able to end itself, either normally or abnormally.
- **I/O Operations**: Control I/O devices such as CDs, DVDs, or screen.
- **File-system Manipulation**: Create, delete, read, write and list files and directories.
- **Communications**: Exchanging information with another process.
	- This can be implemented by:
		- **Shared Memory**: Two or more processes read and write to a shared section of memory.
		- **Message Passing**: Packets of information are moved between processes by the operating system.
- **Error Detection**: Detect components errors.
	- Some errors for example:
		- Memory error.
		- Power failure.
		- Parity error on disk.
		- Connection failure on a network.
		- Lack of paper in the printer.

Another set of services exists for ensuring the efficient operation of the system itself.

- **Resource allocation**: Allocates resources to multiple jobs or users.
- **Accounting**: Keep track of the usage of individual users.
- **Protection and Security**:
	- Protects information from unauthorised processes.
	- Protects system resources.
	- Use authentications.
	- Defending external I/O devices from invalid access attempts.

## Interfaces

Two fundamental approches for users to interface with the operating system is listed below:

- **Command Interpreters**
	- The interpreters are known as **shells**.
	- The commands include create, delete, list, print, copy, execute, and so on.
	- There are two ways to implement the commands:
		- The code is built into the interpreter. 
			1. User enters a command.
			2. The interpreter jumps to the corresponding section and execute the code.
		- The interpreter locate the file corresponding to the command. (Used by UNIX and most systems)
			1. Note that the interpreter does not understand the code.
			2. User enters a command.
			3. Interpreter uses the command to identify a file to execute.
			4. In this way, programmers can add new commands by creating new files with proper names.
- **Graphical User Interfaces**
	- Users use a mouse-based window-and-menu system.

## Components and Interconnections

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.