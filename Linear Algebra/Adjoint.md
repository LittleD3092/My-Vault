Tag: #linear-algebra 
Previous: 
Link: [[Inverse of Matrix]]

---

[TOC]

---

An adjoint of a [[Matrix]] is the transpose of cofactor matrix.

$$\text{adj}A = C^T$$

> The cofactor matrix $C$ is calculated by
> $$c_{ ij } = (-1)^{ i + j } \times \text{ minor of }a_{ ij }$$
> And the minor of $a_{ij}$:
> $$\text{ for a matrix }A = \left[ \begin{array}{} a_{ 11 } & a_{ 12 } & a_{ 13 } \\ a_{ 21 } & a_{ 22 } & a_{ 23 } \\ a_{ 31 } & a_{ 32 } & a_{ 33 } \end{array} \right]$$
> $$\text{ minor of }a_{ 11 } = \left\vert \begin{array}{} a_{ 22 } & a_{ 23 } \\ a_{ 32 } & a_{ 33 } \end{array} \right\vert$$

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.