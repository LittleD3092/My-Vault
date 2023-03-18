標籤: #algorithm 

---

[TOC]

---

Insertion sort works the way many people sort a hend of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To find the correct position for a card, we compare it with each of the cards in hand.

# Pseudocode

```cpp
for j = 2 to A.length
	key = A[j]
	// Insert A[j] into the sorted sequence A[1..j - 1].
	i = j - 1
	while i > 0 and A[i] > key
		A[i + 1] = A[i]
		i = i - 1
	A[i + 1] = key
```

# Loop Invariants

The index $j$ indicates the "current card" being inserted into the hand. The subarray $A[i..j - 1]$ are the elements originally in positions $1$ through $j - 1$, but now in sorted order. We state these properties of $A[1..j - 1]$ formally as a ==loop invariant==:

> At the start of each iteration of the for loop, the subarray $A[1..j - 1]$ consists of the elements originally in $A[1..j - 1]$, but in sorted order.

![[Loop Invariants]]

---

參考資料:

Introduction to Algorithms, third edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.