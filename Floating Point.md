Tag: #computer-organization 
Previous: [[Data Representation]]
Link: 

[TOC]

---

# Single Precision

Representation:

```
| 31    | 30    23 | 22                    0 |
| ----- | -------- | ----------------------- |
| s     | exponent | fraction                |
  1 bit     8bits           23 bits
```

In general, floating-point numbers are of the form:

$$(-1)^S \times F \times 2^E$$

> Single precision is `float` in C.

# Double Precision

Representation:

```
| 31    | 30       19 | 18                 0 |
| ----- | ----------- | -------------------- |
| s     | exponent    | fraction             |
  1 bit     11 bits            20 bits
| fraction (continued)                       |
                   32 bits
```

> Double precision number is not in MIPS. It is in [[#IEEE754]], which is explaned in the following section.

# IEEE754

| Single Precision |          | Double Precision |          | Object represented          |
| ---------------- | -------- | ---------------- | -------- | --------------------------- |
| Exponent         | Fraction | Exponent         | Fraction |                             |
| 0                | 0        | 0                | 0        | 0                           |
| 0                | Nonzero  | 0                | Nonzero  | $\pm$ denormalized number   |
| 1-254            | Anything | 1-2046           | Anything | $\pm$ floating-point number |
| 255              | 0        | 2047             | 0        | $\pm$ infinity              |
| 255              | Nonzero  | 2047             | Nonzero  | NaN (Not a Number)          | 

In IEEE754, the exponent is represented in different way. The exponent is represented in [[Biased Notation]], where the smallest number is represented in `0b0000...0000`, and the greatest number is represented in `0b1111...1111`.

Some examples of [[Biased Notation]]:

$$
\begin{array}{}
	-1 & \implies & -1 + 127 & = & 126 & = & \rm 0b0111\,1110 \\
	+1 & \implies & +1 + 127 &=& 128 &=& \rm 0b1000\,0000 
\end{array}
$$

- The exponent bias for [[#Single Precision]] is 127.
- The exponent bias for [[#Double Precision]] is 1023.

## IEEE754 support in MIPS

MIPS supports the IEEE754 single precision and double precision formats with the instruction below:

| Name                          | Instruction (single)                  | Instruction (double) | Comments                                                                                                                                      |
| ----------------------------- | ------------------------------------- | -------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| Floating-point addition       | `add.s`                               | `add.d`              |                                                                                                                                               |
| Floating-point subtraction    | `sub.s`                               | `sub.d`              |                                                                                                                                               |
| Floating-point multiplication | `mul.s`                               | `mul.d`              |                                                                                                                                               |
| Floating-point division       | `div.s`                               | `div.d`              |                                                                                                                                               |
| Floating-point comparison     | `c.x.s`                               | `c.x.d`              | `x` may be equal (`eq`), not equal (`neq`), less than (`lt`), less than or equal (`le`), greater than (`gt`), or greater than or euqal (`ge`) |
| Floating-point branch         | `bc1t` for true, and `bc1f` for false | same as single       |                                                                                                                                               |

---

# Reference

Computer Organization and Design, 5th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.