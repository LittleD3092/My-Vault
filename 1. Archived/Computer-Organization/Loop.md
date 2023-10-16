Tag: #computer-organization #network-science 
Previous: [[Instructions]], [[Network Science]]
Link: 

[TOC]

---

# Computer Organization

## MIPS

Loop written in MIPS assembly code is a part of script that is composed of labels, jumps, branches and other instructions. Here is an example: [[#Equal and Not Equal Condition Loop]]

### Equal and Not Equal Condition Loop

A traditinal loop in C:

```c
while(save[i] == k)
    i + 1;
```

Assume that `i` and `k` correspond to registers `$s3` and `$s5`, and the base of array `save` is in `$s6`. The corresponding MIPS assembly code is:

```s
Loop:   sll  $t1, $s3, 2    # $t1 = i * 4
		add  $t1, $t1, $s6  # $t1 = save + i * 4
		                    #     (address of save[i])
		lw   $t0, 0($t1)    # $t0 = save[i]
		bne  $t0, $s5, Exit # goto Exit if save[i] neq k
		addi $s3, $s3, 1    # i = i + 1
		j    Loop           # goto Loop
Exit:
```

### Less Than and Greater Than Condition

The above example shows how to write equal and not equal conditions. To use less than or greater than condition, you can use the following listed instructions `slt`, `slti` with `bne`, `be`.

| Name                             | Instruction                                       | Comment                |
| -------------------------------- | ------------------------------------------------- | ---------------------- |
| Set less than                    | `slt $t0, $s3, $s4`                               | `$t0 = 1 if $s3 < $s4` |
| Set less than immediate          | `slti $t0, $s2, 10`                               | `$t0 = 1 if $s2 < 10`  |
| Set less than unsigned           | `sltu destination_register, register1, register2` |                        |
| Set less than immediate unsigned | `sltiu destination_register, register, constant`  |                        |

# Network Science

A loop is a walk that has the same start and end.

The total number of loops of length $r$ is:

$$L_r = \sum_{i = 1}^n [{\bf A}^r]_{ii} = {\rm Tr}({\bf A}^r)$$

- $\rm Tr$: Trace of a matrix (sum of the main diagonal).

---

# Reference

Computer Organization and Design, 5th edition
Network Science Course

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.