Tag: #fluid-mechanics 
Previous: 
Link: [[Dimension]]

---

[TOC]

---

This theorem helps us to determine the dimensionless groups for a problem. It let us to use smaller scales for testing and still acheive the same physical properties.

# Theorem

Buckingham Pi theorem states that we can transform a relationship between $n$ parameters of the form

$$g(q_1, q_2, \dots, q_n) = 0$$

to

$$G(\Pi_1, \Pi_2, \dots, \Pi_{n - m})$$

- $m$ is *usually* the minimum number of independent dimensions.

## Steps

1. *List all the dimensional parameters involved.*
	- Let $n$ be the number of parameters.
2. *Select a set of fundamental (primary) dimensions*.
	- For example, $MLt$ or $FLt$.
	- For heat transfer problems, you may need temperature $T$.
	- For electrical systems, you may need charge $q$.
3. *List the dimensions of all parameters in terms of primary dimensions*.
	- Let $r$ be the number of primary dimensions.
4. *Select a set of $r$ dimensional parameters that includes all the primary dimensions.*
	- No repeating parameter should have dimensions that are a power of the dimensions of another repeating parameter.
	- We usually select simpler parameters like $\rho$, $V$, $D$ instead of $\mu$.
5. *Set up dimensional equations, combining the parameters in step 4 with each of the other parameters in turn, to form dimensionless groups*.
	- There will be $n - m$ equations.
6. *Check to see that each group obtained is dimensionless*.

## Example

Suppose we are finding the properties that [[Drag]] $F$ on a sphere depends on. We can say that $F$ is:

$$F = f(D, \rho, \mu, V)$$

More formally, we write:

$$g(F, D, \rho, \mu, V) = 0$$



---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.