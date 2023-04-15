Tag: #computer-organization 
Previous: [[Instructions]]
Link: 

[TOC]

---

In [[Machine Code#I-type Instructions]], we can see that I-type instructions have a 16-bit immediate field. What if we want bigger constant?

The [[Load Upper Immediate Instruction]] loads the constant to the left 16 bits of the destination register, which we can use to assign bigger constant.

For example, to load a 32-bit constant below into register `$s0`:

```
0000 0000 0011 1101 0000 1001 0000 0000
```

We can use the following instructions:

```s
lui $s0, 61        # 61 = 0b0000_0000_0011_1101
ori $s0, $s0, 2304 # 2304 = 0b_0000_1001_0000_0000
```

> When the assembler need to break and store bigger constants, `$at` (assembler temporary) is actually used.

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.