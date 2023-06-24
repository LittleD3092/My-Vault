Tag: #computer-organization 
Previous: [[Translating Program]]
Link: 

[TOC]

---

- Object files are files that are converted from assembly code. See [[Translating Program]] for a flowchart for compiling programs.
- The object file contains 6 parts:
	- [[Object File Header]]: Describes size and position of other parts.
	- [[Text Segment]]: Machine code.
	- [[Static Data Segment]]: Data allocated for the life of the program.
	- [[Relocation Information]]: Instructions and data words that depend on absolute addresses when the program is loaded into the memory.
	- [[Symbol Table]]: The remaining labels that are not defined, such as external references.
	- [[Debugging Information]]: Description of how the modules are compiled so that a debugger can associate machine instructions with C source file.

---

# Reference

Computer Organization and Design,, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.