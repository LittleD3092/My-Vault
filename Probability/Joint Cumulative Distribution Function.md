Tag: #probability 
Previous: [[Joint Distributions Relationships.canvas|Joint Distributions Relationships]]
Link: 

---

Joint CDF defines the CDF on multiple random variables. Let $X$ and $Y$ be two random variables defined on the same sample space $\Omega$. The joint CDF $F_{XY}(t, u)$ is

$$
F_{XY}(t, u) = P(X \leq t, Y \leq u), \qquad \forall t, u \in \mathbb R
$$

# Example

## 1. Joint CDF of a rectangle area

A joint CDF is given as:

$$F_{XY}(t, u) = P(X \leq t, Y \leq u), \qquad \forall t, u \in \mathbb R$$

1. What is $P(t_1 < X \leq t_2, u_1 < Y \leq u_2)$?
2. What is $P(t_1 < X < t_2, u_1 < Y \leq u_2)$

---

![[Pasted image 20241103163051.png|250]]

From the above graph, we can see that the answer should be:

$$
P(t_1 < X \leq t_2, u_1 < Y \leq u_2) = F_{XY}(t_2, u_2) - F_{XY}(t_1, u_2) - F_{XY}(t_2, u_1) + F_{XY}(t_1, u_1)
$$

For the second case, we only need to change $t_2$ to $t_2^-$:

$$
P(t_1 < X < t_2, u_1 < Y \leq u_2) = F_{XY}(t_2^-, u_2) - F_{XY}(t_1, u_2) - F_{XY}(t_2^-, u_1) + F_{XY}(t_1, u_1)
$$

## 2. Joint CDF of a unit square

Suppose a point $(X, Y)$ is selected randomly from the unit square 

$$D = \{(x, y): 0 \leq x \leq 1, 0 \leq y \leq 1\}.$$

What is the joint CDF of $X$ and $Y$, $F_{XY} (t, u)$?

---

There are 5 cases to consider:

![[Pasted image 20241103163733.png|250]]

$$
F_{XY}(t, u) = P(X \leq t \text{ and } Y \leq u) = \left\{
	\begin{array}{rl}
		1, & \text{if }(t, u) \in (\rm I) \\
		u, & \text{if } (t, u) \in (\rm II) \\
		t, & \text{if } (t, u) \in (\rm III) \\
		tu, & \text{if } (t, u) \in (\rm IV) \\
		0, & \text{if } (t, u) \in (\rm V)
	\end{array}
\right.
$$

When considering joint CDF, we need to be careful about all the cases.

## 3. Joint CDF of a joint PDF

The joint PDF of $X$ and $Y$ is:

$$
f(x, y) = \left\{
	\begin{array}{rl}
		\displaystyle \frac 3 2 (x^2 + y^2), & \text{if } 0 < x < 1 \text{ and } 0 < y < 1 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

What is the joint CDF of $X$ and $Y$?

---

There are 5 cases to consider:

![[Pasted image 20241103195525.png|250]]

$$
\begin{array}{rrl}
	\rm (I): & F_{XY}(t, u) &=& 1 \\
	\rm (II): & F_{XY}(t, u) &=& \displaystyle \int_0^u \int_0^1 f_{XY}(x, y)dxdy\\
	\rm (III): & F_{XY}(t, u) &=& \displaystyle \int_0^1 \int_0^t f_{XY}(x, y)dxdy\\
	\rm (IV): & F_{XY}(t, u) &=& \displaystyle \int_0^u \int_0^t f_{XY}(x, y)dxdy\\
	\rm (V): & F_{XY}(t, u) &=& 0
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.