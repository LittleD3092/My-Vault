Tag: #linear-algebra 
Previous: 
Link: 

---

[TOC]

---

# Determine Linear Dependency

Assume there are [[Vector]]s ${\bf v}_1, {\bf v}_2, \dots, {\bf v}_n$ that [[Span]] [[Vector Space]] $V$,

1. If one of the [[Vector]]s can be written as a linear combination of the other $n - 1$ [[Vector]]s, then those $n - 1$ [[Vector]]s [[Span]] $V$.
2. If it is possible to have scalars $c_1, c_2, \dots, c_{n}$ (not all zero) that $$c_1 {\bf v}_1 + c_2 {\bf v}_2 + \dots + c_n {\bf v}_n = {\bf 0}$$, then it is linear dependent.

# Definition

We can obtain the definition of linear independent using section [[#Determine Linear Dependency]].

> The vectors ${\bf v}_1, {\bf v}_2, \dots, {\bf v}_n$ in a vector space $V$ are said to be **linearly independent** if
> $$c_1 {\bf v}_1 + c_2 {\bf v}_2 + \dots + c_n {\bf v}_n = {\bf 0}$$
> implies that all the scalars $c_1, c_2, \dots, c_n$ must equal $0$.

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.