Tag: #network-science 
Previous: [[Robustness and Resilience of a Network]]
Link: [[Perlocation Threshold]]

[TOC]

---

Molly-Reed criterion can be used to calculate the robustness ([[Perlocation Threshold|perlocation threshold]] $f_c$). (<u>2</u>)

# Theory

In order for a network to have a giant component, on average each node should have at least two links. (<u>1</u>)

$$\kappa = \frac{\langle k^2 \rangle}{\langle k \rangle} > 2$$

If the above formula is not satisfied, the network is fragmented into many disconnected components. (<u>1</u>)

# Critical Threshold

Using the [[#Theory|theory]], we can get the critical threshold $f_c$:

$$
\begin{array}{}
	f_c &=&
	\displaystyle
	1 - \frac{1}{\frac{\langle k^2 \rangle}{\langle k \rangle} - 1}
\end{array}$$

The formula can be further derived into random graph's formula and scale-free's formula:

$$
\left\{
	\begin{array}{l}
		f_c^{\rm ER} &=& 
		\displaystyle
		1 - \frac{1}{\langle k \rangle} \\
		f_c^{\rm SF} &=&
		\displaystyle
		1 - \frac{1}{\frac{\infty}{\langle k \rangle} - 1} &=&
		1
	\end{array}
\right.
$$

---

# Reference

1. Y. Lou, “Network Science, Lecture 8: Robust and Resiience, part 2,” NYCU ED102[GF], Nov. 21, 2023.
2. “Robustness of complex networks,” Wikipedia. Jul. 29, 2022. Accessed: Dec. 18, 2023. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Robustness_of_complex_networks&oldid=1101190478


---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.