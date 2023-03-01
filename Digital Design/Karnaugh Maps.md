Tag: #電工學 
Previous: 
Link: [[Logic Circuits]]

[TOC]

---

- 我們可以利用 Karnaugh maps 來化簡 [[Boolean Function]]
- Looks like a [[Truth Table]].
- Also known as [[K-Map]].
- Steps:
	1. 根據輸入端的個數畫一個正方形或長方形
	2. 在旁邊標上輸入端的字母與輸入訊號，輸入訊號使用 gray signal
	3. 將輸出訊號填到格子裡
	4. 用大括號將 $A, B, C, D$ 為 1 的地方括起來
	5. 嘗試用 $A, B, C, D$ 表示運算式

![[karnaugh maps.png]]

# Two-Variable K-Map

![[Pasted image 20230301184109.png|500]]

- Consists of 4 [[Minterms]]

---

Example:

$$m_1 + m_2 + m_3$$

![[Pasted image 20230301184225.png|500]]

$$ = x'y + xy' + xy = x + y$$

# Three-Variable K-Map

![[Pasted image 20230301184325.png|500]]

- [[Minterms]] are arranged in [[Grey Code]]
	- Only one bit changes from adjacent column or row.
- Rules:
	- *Following list shows how you can group squares:*
	- 1 square: 1 minterm, 3 literals.
	- 2 adjacent squares: a term with 2 literals.
	- 4 adjacent squares: a term with 1 literal.
	- 8 adjacent squares: Constant 1.

---

Example:

$$m_5 + m_7$$

By the graph above,

$$ = xy'z + xyz = xz$$

---

Example:

$$\sum(2, 3, 4, 5)$$

![[Pasted image 20230301184611.png|500]]

$$ = x'y + xy'$$

---

Example:

$$m_0 + m_2$$

By constructing K-map:

$$ = x'z'$$

> Note that $m_0, m_2$ are adjacent, though they do not touch.

---

Example:

$$m_4 + m_6$$

By constructing K-map:

$$ = xz'$$

> Note that $m_4, m_6$ are adjacent, though they do not touch.

---

Example:

$$F(x, y, z) = \sum(3, 4, 6, 7)$$

![[Pasted image 20230301184937.png|500]]

$$ = yz + xz'$$

---

Example:

$$m_0 + m_2 + m_4 + m_6$$

By constructing K-map,

$$ = z'$$

---

Example:

$$F(x, y, z) = \sum(0, 2, 4, 5, 6)$$

![[Pasted image 20230301185319.png|500]]

$$ = z' + xy'$$

---

Example:

$$F = A'C + A'B + AB'C + BC$$

![[Pasted image 20230301185436.png|500]]

$$ = \sum(1, 2, 3, 5, 7) = F = C + A'B$$

# Four-Variable K-Map

![[Pasted image 20230301190958.png|500]]

- 4 binary variables ($w, x, y, z$)
- The rows and columns are numbered in a [[Grey Code]] sequence.
- Rules:
	- 1 square: 1 minterm, 1 term with 4 literals.
	- 2 adjacent squares: 1 term with 3 literals.
	- 4 adjacent squares: 1 term with 2 literals.
	- 8 adjacent squares: 1 term with 1 literal.
	- 16 adjacent squares: Constant 1.

---

Example:

$$F(w, x, y, z) = \sum(0, 1, 2, 4, 5, 6, 8, 9, 12, 13, 14)$$

![[Pasted image 20230301191650.png|500]]

$$ = y' + w'z' + xz'$$

---

Example:

$$F = A'B'C' + B'CD' + A'BCD' + AB'C'$$

![[Pasted image 20230301191905.png|500]]

$$ = B'C' + B'D' + A'CD'$$

# Prime Implicant

- A product term with maximum number of adjacent squares.
- If a square is covered by only 1 prime implicant, the prime implicant is **essential**.

![[Pasted image 20230301192444.png|500]]

# Examples

> Recall:
> - SOP stands for sum of product.
> - POS stands for product of sum.

## SOP Example

> A logic circuit has inputs $A, B, C, D$. The output of the circuit is given by
> $$E = \sum m(1, 3, 4, 5, 7, 10, 12, 13)$$
> Find the minimum SOP form for $E$

convert the numbers of the minterms to binary numbers

$$
\begin{array}{}
	\text{ number } & \text{ binary } \\
	1 & 0001 \\
	3 & 0011 \\
	4 & 0100 \\
	5 & 0101 \\
	7 & 0111 \\
	10 & 1010 \\
	12 & 1100 \\
	13 & 1101
\end{array}
$$

Construct Karnaugh maps

![[Karnaugh maps SOP example.png|300]]

draw squares on the map and get SOP expression

$$E = \overline A D + B \overline C + A \overline B C \overline D$$

## POS Example

> Find the minimum POS for the logic variable $E$ of last example

draw Karnaugh maps

![[Karnaugh maps for POS example.png|300]]

obtain expression

$$\overline E = ABC + A \overline B D + \overline A C \overline D + \overline B\, \overline C\, \overline D$$

apply De Morgan's laws

$$E = (\overline A + \overline B + \overline C)(\overline A + B + \overline D)(A + \overline C + D)(B + C + D)$$

---

Reference:

電工學課本
Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.