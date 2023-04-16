Tag: #computer-organization 
Previous: [[Computer Organization]]
Link: 

[TOC]

---

Little-endian and big-endian stands for the order that bytes are stored in memory.

For example, `0x12345678` in little-endian machine is stored like this:

| address | value |
| ------- | ----- |
| `0`     | `78`  |
| `1`     | `56`  |
| `2`     | `34`  |
| `3`     | `12`  | 

In big-endian machine, it is stored like this:

| address | value |
| ------- | ----- |
| `0`     | `12`  |
| `1`     | `34`  |
| `2`     | `56`  |
| `3`     | `78`  | 

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.