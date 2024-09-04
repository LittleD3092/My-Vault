Tag: #statistics 
Previous: [[Continuous Random Variables]]
Link: 

---

A probability density function can show the probability distribution of a [[Continuous Random Variables|continuous random variable]]. (<u>1</u>)

![[Pasted image 20240303161734.png|300]]

To calculate the probability of an interval, we can use integral: (<u>1</u>)

$$P(a < X < b) = \int_a^b f(x)dx$$

There are some properties of the probability density function: (<u>1</u>)

- $f(x) \geq 0$: Always greater than $0$.
- $\int_{-\infty}^\infty f(x)dx = 1$: The sum of the function is always $1$.
- $P(a\leq X\leq b) = P(a\leq X < b) = P(a < X \leq b) = P(a < X < b)$: The inclusive and exclusive ranges don't matter.
- $P(x = a) = 0$: There is $0$ probability for a specific $x$.

---

# Reference

1. Y.-J. Tseng, “Statistics, Chapter 1: The Role of Statistics,” NYCU ED302, Feb. 29, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.