Tag: #operating-system #list 
Previous: 
Link: 

[TOC]

---

# Chapter 1: Introduction

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

# Chapter 2: System Structures

## View of Operating System

We can view operating system based on 3 aspects:

- [[#Services]]
- [[#Interfaces]]
- [[#Components and Interconnections]]

### Services

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

### Interfaces

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

#### System Call

System calls provide an interface to the services.

> [[System Call]]

### Components and Interconnections

#### System Programs

[[System Programs|System programs]], also known as system utilities, provide a convenient environment for program development and execution.

> [[System Programs]]

#### Design Factors

- The design may be affected by the choice of hardware and the type of system. Some factors:
	- Batch
	- Time sharing
	- Single user / Multiuser
	- Distributed
	- Real time
	- General purpose
- The requirements can be divided into two groups:
	- **User goals**
		- Convenient to use.
		- Easy to learn and to use.
		- Reliable.
		- Error free.
		- Efficient.
	- **System goals**
		- Distribute resources efficiently.

There is no best solutions to these requirements, but there are some principles:

- Separation of **policy** from **mechanism**.
	- **policy**: The part of *what* will be done.
	- **mechanism**: The part of *how* to do something.

> For example, how a timer construct works is **mechanism**, and how long the timer should be set is **policy**.
> The **mechanism** can be fixed, and **policy** may vary depending on the requirements.

## Structure

There are different kinds of structures. Some are divided into **modules**, some are not.

### Simple Structure

- Many operating systems do not have well-defined structures.
- Such systems started as small and limited systems, then grew beyond its original scope.
- Example: MS-DOS, original UNIX.

### Layered Approach

- One of the methods to make a system modular is the **layered approach**,
- The operating system is broken into a number of layers.
	- The bottom layer (layer 0) is the hardware.
	- The highest layer (layer N) is the user interface.

![[Pasted image 20230624151204.png|250]]

- Advantage: Simplicity of construction and debugging.
	- The layers only uses functions, operations, and services from lower levels.
- Disadvantage: The difficulty when defining the various layers.

### Microkernels

- As UNIX expanded, the kernel became large and difficult to manage.
- This method structures the operating system by removing all nonessential components from the kernel and implementing them as system and user-level programs.

![[Pasted image 20230624152151.png|400]]

- The main function of the microkernel is to provide communication between programs and services in user space.
	- The communication is provided through [[Message Passing|message passing]].
- Disadvantage: The performance can suffer due to increased system-function overhead.

### Modules

- Using **loadable kernel modules**.
	- Has a set of core components.
	- The core components links additional services via modules.
- The best for now.
- Example:
	- Build CPU scheduling and memory management into the kernel.
	- Add support for different file systems by loadable modules.
- Similar, but more flexible compared to [[#Layered Approach]].

![[Pasted image 20230626171104.png|400]]

### Hybrid Systems

- In practice, operating systems combine different structure, resulting in hybrid systems.
- Example:
	- Linux and Solaris are monolithic, because it provides very efficient performance.
	- They are also modular, so that new functionality can be added.
- Another example:
	- Windows is monolithic, for performance reasons.
	- It has some behavior of microkernels, providing support for separate subsystems.

## Debugging

- Note: debugging can also include **performance tuning**, by removing processing **bottlenecks**.

### Failure Analysis

For user processes:

- If a process fails, most operating systems write the error information to a **log file**.
- The operating system can also take a **core dump** and store it in a file.
	- **Core dump**: A capture of the memory of the process.

For operating system kernels:

- A failure in the kernel is called a **crash**.
- When a crash happens:
	- Error information is saved to a log file.
	- Memory state is saved to a **crash dump**.

### Performance Tuning

- The operating system produces **trace listings** of system behavior.
	- Interesting events are logged with their time and important parameters.
	- The trace listings are written to a file.

# Chapter 3: Process

A process can be thought of as a program in execution.

> [[Process]]

# Chapter 4: Threads

> [[Threads]]

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.