Tag: #computer-organization 
Previous: [[Instructions]]
Link: 

[TOC]

---

- In MIPS, 32 bits group is a **word**.
- In MIPS, length of words must be multiples of 4.

# Memory Operands

- **Data transfer instructions**: Transfer data between memory and registers.

---

## Example 1

Write the following C++ code in assembly.

```cpp
g = h + A[8]
```

Assume `g` is in `$s1`, `h` is in `$s2`, `A` is in `$s3`.

Assume the increment of the address is by words.

![[Pasted image 20230312164934.png]]

---

```armasm
lw $t0, 8$(s3)
add $s1, $s2, $t0
```

> `8` is the **offset**, and `$s3` is the **base register**.

## Example 2

Write the following C++ code in assembly.

```cpp
A[12] = h + A[8]
```

Assume `A` is in `$s3`, `h` is in `$s2`.

Different from [[#Example 1]], in actual MIPS instruction, addresses are multiples of 4.

![[Pasted image 20230312170956.png]]

---

```armasm
lw $t0, 32($s3)
add $t0, $s2, $t0
sw $t0, 48($s3)
```

# Constant or Immediate Operands

For adding a constant:

```armasm
addi $s3, $s3, 4    // $s3 = $s3 + 4
```

For constant `0`, we have a constant zero register `$zero`.

---

# Reference

Computer Organization and Design, 5th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.