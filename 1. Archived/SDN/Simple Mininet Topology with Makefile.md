Tag: #SDN #code-project-managing-tool 
Previous: [[Simple Mininet Topology]]
Link: 

[TOC]

---

The `makefile` of starting a [[Simple Mininet Topology|simple mininet topology]] can be written as (<u>1</u>):

```makefile
start:
	sudo mn --topo single,3 --mac --controller remote

stop:
	sudo mn -c
```

---

# Reference

1. Github, Copilot. “How Do I Create a Make File That Establish Mininet for Me?,” October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.