Tag: #linear-algebra 
Previous: 
Link: 

---

[TOC]

---

- We can perform *exactly one* [[Elementary Row Operation]] to an [[Identity Matrix]] $I$. The resulting matrix is called an *elementary matrix*.
- There are 3 types:
	1. Interchanging two rows.
		- Example: $$E_1 = \left[ \begin{array}{} 0 & 1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1\end{array} \right]$$
		- Meaning:
			- $E_1A$ exchanges two rows of $A$. $$E_1A = \left[ \begin{array}{} 0 & 1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1 \end{array} \right] \left[ \begin{array}{} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{array} \right] = \left[ \begin{array}{} a_{21} & a_{22} & a_{23} \\ a_{11} & a_{12} & a_{13} \\ a_{31} & a_{32} & a_{33} \end{array} \right]$$
			- $AE_1$ exchanges two columns of $A$. $$AE_1 = \left[ \begin{array}{} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{array} \right] \left[ \begin{array}{} 0 & 1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1 \end{array} \right] = \left[ \begin{array}{} a_{12} & a_{11} & a_{13} \\ a_{22} & a_{21} & a_{23} \\ a_{32} & a_{31} & a_{33} \end{array} \right]$$
	1. Multiplying a row by a nonzero constant.
		- Example: $$E_2 = \left[ \begin{array}{} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 3 \end{array} \right]$$
		- Meaning:
			- $E_2A$ multiplies the row of $A$. $$E_2A = \left[ \begin{array}{} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 3 \end{array} \right]\left[ \begin{array}{} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{array} \right] = \left[ \begin{array}{} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ 3a_{31} & 3a_{32} & 3a_{33} \end{array} \right]$$
			- $AE_2$ multiplies the column of $A$. $$AE_2 = \left[ \begin{array}{} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{array} \right]\left[ \begin{array}{} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 3 \end{array} \right] = \left[ \begin{array}{} a_{11} & a_{12} & 3a_{13} \\ a_{21} & a_{22} & 3a_{23} \\ a_{31} & a_{32} & 3a_{33} \end{array} \right]$$
	1. Adding a multiple of one row to another row.
		- Example: $$E_3 = \left[ \begin{array}{} 1 & 0 & 3 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{array} \right]$$
		- Meaning:
			- $E_3A$ adds a multiple of the row to the other row. $$E_3A = \left[ \begin{array}{}  \end{array} \right]$$
			- $AE_3$ adds a multiple of the column to the other column.

---

參考資料:

Linear Algebra with Applications, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.