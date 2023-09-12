Tag: #computer-organization 
Previous: [[Instructions]]
Link: 

[TOC]

---

Each instruction in MIPS instruction set takes 32 bits. There are three types of instructions, each has different ways of using the 32 bits:

- [[#R-type Instructions]]
- [[#I-type Instructions]]
- [[#J-type Instructions]]

## R-type Instructions

R stands for register.

Common operations use this type, such as `add`.

| op     | rs     | rt     | rd     | shamt  | funct  |
| ------ | ------ | ------ | ------ | ------ | ------ |
| 6 bits | 5 bits | 5 bits | 5 bits | 5 bits | 6 bits | 

- `op`: Operation. Also called [[Opcode]].
- `rs`: First register source operand.
- `rt`: Second register source operand.
- `rd`: Register destination operand. Gets the result.
- `shamt`: Shift amount.
- `funct`: Function. Selects the specific variant of the operation. Also called [[Function Code]].

## I-type Instructions

I stands for immediate. 

Because we wish to operate larger constant, I-type instructions give the constant a 16-bit range. Also, the `rd`, `shamt` and `funct` are removed to save space for constant field.

Some operations that require a constant are this type. Examples: add immediate `addi`, branch and compare branch `b`, `beq`, `bne` etc.

| op     | rs     | rt     | constant or address |
| ------ | ------ | ------ | ------------------- |
| 6 bits | 5 bits | 5 bits | 16 bits             | 

## J-type Instructions

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.