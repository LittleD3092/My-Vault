Tag: #operating-system 
Previous: [[Operating System]]
Link: 

[TOC]

---

# System Programs

[[System Programs|System programs]], also known as system utilities, provide a convenient environment for program development and execution.

> [[System Programs]]

# Design Factors

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

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.