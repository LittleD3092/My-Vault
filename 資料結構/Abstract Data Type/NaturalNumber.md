標籤: #DataStructure 

---

# Objects

An ordered subrange of the integers starting at zero and ending at the maximum integer(`MAXINT`) on the computer.

# Functions

For all $x, y\in \text{NaturalNumber}$, 
$\text{TRUE, FALSE}\in\text{Boolean}$
and where $+, -, <, ==,$ and $=$ are the usual integer operations

| Functions          | Result        | Is Defined As                                                                                                                       |
| ------------------ | ------------- | --------------------------------------------------------------------------------------------------------------------------- |
| $$Zero()$$         | NaturalNumber | $$0$$                                                                                                                       |
| $$IsZero(x)$$      | Boolean       | $$\begin{array}{l}\text{\bf if}(x==0) & IsZero=\text{\bf true} \\ \text{\bf else} & IsZero=\text{\bf false}\end{array}$$    |
| $$Add(x, y)$$      | NaturalNumber | $$\begin{array}{l} \text{\bf if}(x+y <= \text{MAXINT}) & Add = x + y \\ \text{\bf else} & Add = \text{MAXINT} \end{array}$$ |
| $$Equal(x, y)$$    | Boolean       | $$\begin{array}{l} \text{\bf if}(x == y) & Equal = \text{TRUE} \\ \text{\bf else} & Equal = \text{FALSE} \end{array}$$      |
| $$Successor(x)$$   | NaturalNumber | $$\begin{array}{l} \text{\bf if}(x==\text{MAXINT}) & Successor = x \\ \text{\bf else} & Successor = x + 1 \end{array}$$     |
| $$Subtract(x, y)$$ | NaturalNumber | $$\begin{array}{l} \text{\bf if}(x < y) & Subtract = 0 \\ \text{\bf else} & Subtract = x - y \end{array}$$                                                                                                                            |

---

參考資料:

Fundamentals of Data Structures in C++, 2nd Edition

---

link:

