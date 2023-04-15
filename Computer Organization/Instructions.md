Tag: #computer-organization 
Previous: 
Link: 

[TOC]

---

- [[Operands]]
- **Signed and Unsigned Number**
	- Ways of representing an unsigned number:
		- [[Sign and Magnitude]]: 1 bit for sign, others for value.
		- [[2's Complement]]

# MIPS

- Instructions:
	- [[Logical Operations]]
	- [[Conditional Instructions]]
- Mechanisms:
	- [[Loop]]
	- [[Function]]

**MIPS assemply language cheat sheet**:

![[Pasted image 20230312164252.png]]

## Machine Code

[[Machine Code]]

# STM32

The following chart show common used assembly instructions in STM32:

| Instruction | Function                                                               | Example        | Explanation                                                     |
| ----------- | ---------------------------------------------------------------------- | -------------- | --------------------------------------------------------------- |
| `LDR`       | Load register.                                                         | `LDR R0, [R1]` | Load the value in the register which has address `R1`.          |
| STR         | Store register.                                                        | `STR R0, [R1]` | Store the value in `R0` to the register which has address `R1`. |
| `MOV`       | Move. Copy the second operand's value to the first operand (register). | `MOV R0, R1`   | Copy `R1`'s value and store it in `R0`.                         | 

---

Reference:

Computer Organization and Design, 5th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.