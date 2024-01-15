Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

- Provide an interface to the services.

Below is an example of copying a file:

![[Pasted image 20230624135446.png|400]]

- The system calls are written in **application programming interface (API)**.
	- Different operating systems have different APIs.
	- APIs provide better portability.

The relationships between API, operating system, and the system call interface:

![[Pasted image 20230624135642.png|400]]

# Types

System calls can be grouped into the following 6 categories:

- **Process control**
	- end, abort
	- load, execute
	- create process, terminate process
	- get process attributes, set process attributes
	- wait for time
	- wait event, signal event
	- allocate and free memory
- **File management**
	- create file, delete file
	- open, close
	- read, write, reposition
	- get file attributes, set file attributes
- **Device management**
	- request device, release device
	- read, write, reposition
	- get device attributes, set device attributes
	- logically attach or detach devices
- **Information maintenance**: transfer information between user process and operating system
	- get time or date, set time or date
	- get system data, set system data
	- get process, file, or device attributes
	- set process, file, or device attributes
- **Communications**
	- create, delete communication connection
	- send, receive messages
	- transfer status information
	- attach or detach remote devices

# Examples

Here are some examples of windows and UNIX system calls:

|                         | Windows                                                                                       | Unix                                                 |
| ----------------------- | --------------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| Process Control         | `CreateProcess()` <br> `ExitProcess()` <br> `WaitForsingleObject()`                           | `fork()` <br> `exit()` <br> `wait()`                 |
| File Manipulation       | `CreateFile()` <br> `ReadFile()` <br> `WriteFile()` <br> `CloseHandle()`                      | `open()` <br> `read()` <br> `write()` <br> `close()` |
| Device Manipulation     | `SetConsoleMode()` <br> `ReadConsole()` <br> `WriteConsole()`                                 | `ioctl()` <br> `read()` <br> `write()`               |
| Information Maintenance | `GetCurrentProcessID()` <br> `SetTimer()` <br> `Sleep()`                                      | `getpid()` <br> `alarm()` <br> `sleep()`             |
| Communication           | `CreatePipe()` <br> `CreateFileMapping()` <br> `MapViewOfFile()`                              | `pipe()` <br> `shm_open()` <br> `mmap()`             |
| Protection              | `SetFileSecurity()` <br> `InitializeSecurityDescriptor()` <br> `SetSecurityDescriptorGroup()` | `chmod()` <br> `umask()` <br> `chown()`              | 

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.