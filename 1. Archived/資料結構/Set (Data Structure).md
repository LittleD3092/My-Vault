標籤: #DataStructure 

---

[TOC]

---

# Disjoint Sets

Disjoint sets are sets that any two sets does not have the same element.

![[possible tree representation of sets - set.png]]

## Union

A union of two sets can be obtained by simply making a tree a subtree of the other. For example, if we wish to obtain a union of $S_1$ and $S_2$, we may get the possible representations like this:

![[possible representations of S_1 S_2 union - set.png]]

- On the left side, we make $S_2$ a subtree of $S_1$
- On the right side, we make $S_1$ a subtree of $S_2$

---

參考資料:

Fundamentals of Data Structures, 2nd edition

---

link:

[[Tree]]