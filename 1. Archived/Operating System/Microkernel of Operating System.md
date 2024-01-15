Tag: #operating-system 
Previous: [[Possible Operating System Structures]]
Link: 

[TOC]

---

- As UNIX expanded, the kernel became large and difficult to manage.
- This method move as much from the kernel into "user" space.

![[Pasted image 20230624152151.png]]

- The main function of the microkernel is to provide communication between programs and services in user space.
	- The communication is provided through [[Message Passing|message passing]].
- Advantage:
	- Easier to extend.
	- Easier to port new functions.
	- More reliable and secure.
- Disadvantage: The performance can suffer due to increased system-function overhead.

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.