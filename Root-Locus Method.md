標籤: #automatic-control 

---

[TOC]

---

- We may have a system transfer function that has an unknown value $K$:
	- $\displaystyle \frac{s^2 + s + 1}{s^3 + 4s^2 + Ks + 1}$
- We wish to find the characteristic equation.
	- Recall that characteristic equation is $\text{denominator} = 0$.
	- The characteristic equation shows the $s$ value that transfer function blows to $\infty$.
- Finding the roots of the characteristic equation of degree higher than 3 is laborious.
- **Root-locus method** is a simple way to find roots $s$ for the characteristic equation.
	- Root-locus simply pick a lot of $K$ and connect the roots $s$ together.
- The method let us solve two questions:
	1. What value $K$ should I use in my control system?
	2. What is the effect $K$ may cause?

# Meaning of Root-Locus Plot

![[Screenshot from 2022-12-14 21-59-57.png]]

- The right of the plot means *unstable*.
- The left of the plot means *stable*.
- The up of the plot means less frequency.
- The down of the plot means more frequency.

# General 

The characteristic equation is given as

$$1 + G(s)H(s) = 0$$

![[Pasted image 20221214235301.png|300]]

First we do is to rearrange this equation to the standard form:

$$
1 + \frac{K(s + z_1)(s + z_2)\dots(s + z_m)}
{(s + p_1)(s + p_2) \dots (s + p_n)} = 0
$$

Then we go through the following steps:

1. Locate the poles and zeros on the $s$ plane.
	- The zeroes are at $s = -z_1, -z_2, \dots, -z_m$. It is often plotted as a circle.
	- The poles are at $s = -p_1, -p_2, \dots, -p_n$.
2. Determine the root loci on the real axis.
	- Find a point on the real axis.
	- If the total number of real poles and real zeros to the right of this test point is odd, then the point is on a root locus.
3. Determine the asymptotes of root loci.
	- There will be $n - m$ asymptotes.
	- The intersection of the asymtotes is at $$s = -\frac{(p_1 + p_2 + \dots + p_n) - (z_1 + z_2 + \dots + z_m)}{n - m}$$
	- The angles of the asymptotes is $$\text{Angles of asymtotes} = \frac{\pm180\degree(2k + 1)}{n - m} \qquad (k = 0, 1, 2, \dots)$$
4. Find the breakaway and break-in points.
	- Suppose the characteristic equation is given by $$B(s) + KA(s) = 0$$
	- Then the breakaway and break-in points are $s$ that satisfy: $$\frac{dK}{ds} = -\frac{B'(s)A(s) - B(s)A'(s)}{A^2(s)} = 0$$
5. Determine the angle of departure (or arrival) from a complex pole (or at a complex zero).
	- First, we draw straight lines from every other points to the point.
	- Then, we mark the angles of the lines compared to the right of the real axis.
		- The poles have angles: $\theta_1, \theta_2, \dots$
		- The zeros have angles: $\phi_1, \phi_2, \dots$
		- ![[Pasted image 20221215002758.png]]
	- For a departure from a complex pole: $$\text{Angle of departure} = 180\degree - \sum\theta_i + \sum\phi_j$$
	- For an arrival at a complex zero: $$\text{Angle of arrival} = 180\degree - \sum\phi_j + \sum\theta_i$$
6. Find the points where the root lici may cross the imaginary axis.
	- You have two ways:
		- [[Routh's Stability Criterion]]
		- Let $s = j\omega$, and let characteristic equation equal to $0$ to solve $s$ and $\omega$.
7. Test a lot of points and draw the root loci.
8. Determine closed-loop poles.
	- The value $K$ corresponding to any point $s$ on a root locus can be obtained using $$K = \frac{\text{product of lengths between }s \text{ to poles}}{\text{product of lengths between } s \text{ to zeros}}$$

# Root Loci of Configurations

This is a table that shows several root loci for reference.

![[Pasted image 20221215004733.png]]

![[Pasted image 20221215004909.png]]

---

參考資料:

Modern Control Engineering, 5th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.