Tag: #computer-graphics 
Previous: [[Line Drawing Algorithms]]
Link: 

[TOC]

---

The previous algorithm [[Digital Differential Analyzer|digital differential analyzer]] has a performance problem. It requires one floating point addition per step, and floating point additions are time consuming. (<u>1</u>)

This algorithm eliminates all floating point numbers. (<u>1</u>)

The code below first shows a floating point edition, which makes more sense, then an integer edition, which avoid division.

```js
// floating point edition
function line(x0, x1, y0, y1)
	int deltax := abs(x1 - x0)
	int deltay := abs(y1 - y0)
	real error := 0
	real deltaerr := deltay / deltax
	int y := y0
	for x from x0 to x1
		plot(x, y)
		error := error + deltaerr
		if error >= 0.5
			y := y + 1
			error := error - 1.0

// integer edition
// this method avoid floating point and division
function line(x0, x1, y0, y1)
	int deltax := abs(x1 - x0)
	int deltay := abs(y1 - y0)
	int error := 0
	int deltaerr := deltay
	int y := y0
	for x from x0 to x1
		plot(x, y)
		error := error + deltaerr
		if 2 * error >= deltax
			y := y + 1
			error := error - deltax
```

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 7: Rasterization.” NYCU EC114[GF], November 8, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.