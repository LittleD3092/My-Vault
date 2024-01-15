Tag: #operating-system 
Previous: [[Possible Operating System Structures]]
Link: 

[TOC]

---

- One of the methods to make a system modular is the **layered approach**,
- The operating system is broken into a number of layers.
	- The bottom layer (layer 0) is the hardware.
	- The highest layer (layer N) is the user interface.

![[Pasted image 20230624151204.png|250]]

- Advantage: Simplicity of construction and debugging.
	- The layers only uses functions, operations, and services from lower levels.
- Disadvantage: The difficulty when defining the various layers.

---

# Reference

- Silberschatz Abraham, Peter Baer Galvin, and Greg Gagne. Operating System Concepts. Ninth edition. John Wiley & Sons, Inc., n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.