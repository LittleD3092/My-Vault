Tag: #computer-organization 
Previous: [[Instructions]]
Link: 

[TOC]

---

Load and store instructions are for manipulating merory that is pointed by an address.

| Name            | Assembly          | Comments                                |
| --------------- | ----------------- | --------------------------------------- |
| Load byte       | `lb $t0, 0($sp)`  | Read byte from source                   |
| Store byte      | `sb $t0, 0($gp)`  | Write byte to destination               |
| Load half word  | `lhu $t0, 0($sp)` | Read halfword (16 bits) from source     |
| Store half word | `sh $t0, 0($gp)`  | Write halfword (16 bits) to destination |
| Load word       | `lw $t0, 0($sp)`  | Read word (32 bits) from source         |
| Store word      | `sw $t0, 0($gp)`  | Write word (32 bits) to destination     | 

---

# Reference


---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.