Tag: #computer-organization #list 
Previous: [[Computer Organization]]
Link: [[ALU (Arithmetic Logic Unit)]], [[Clock Cycle Time]]

[TOC]

---

# Basic Implementation

To implement the instructions, we first examine some important instructions:

- `lw` (load word), `sw` (save word)
- `add`, `sub`, `and`, `or`, `slt`
- `beq` (branch equal), `j` (jump)

We can observe the instructions have the first 2 identical steps:

1. Send **program counter (pc)** to instruction memory, then the instruction is fetched.
2. Decode the instruction to several fields, and read one or two registers.

So the abstract view of the implementation should look like this:

![[Pasted image 20230527171108.png]]

1. Instructions start by sending program counter into instruction memory.
2. The register index are decoded from instruction and sent into registers.
3. The register operands are fetched by ALU.
4. The ALU save the result into register, or the result is an address for `lw` or `sw`.
5. The program counter is added, and go back to step 1.

To decode the instruction and control the signals, a control unit (or decode unit) is required:

![[Pasted image 20230527171305.png]]

- The top [[Multiplexer|multiplexer]] choose between PC+4 or the branch destination address.
- The middle [[Multiplexer|multiplexer]] choose between the output of the ALU and the data memory (for `lw`).
- The lower [[Multiplexer|multiplexer]] choose between the output of register or an immediate value in the instruction.

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.