Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

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

# System Call

System calls provide an interface to the services.

> [[System Call]]

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.