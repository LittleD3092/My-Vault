Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

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

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.