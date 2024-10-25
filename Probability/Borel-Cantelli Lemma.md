Tag: #probability 
Previous: [[Probability]]
Link: 

---

$E_1, E_2, \dots$ are events. The Borel-Cantelli lemma states that if the sum of the probabilities of the events is infinite, the probability of limit supremum is 0. (<u>1</u>)

$$
\begin{array}{rl}
	\text{if } & \displaystyle
	\sum_{n = 1}^\infty \Pr(E_n) < \infty \\
	\text{then} & \displaystyle \Pr\left(
		\bigcap_{n = 1}^\infty
		\bigcup_{k = n}^\infty
		E_k
	\right) = 0
\end{array}
$$

# Example

## 1. Proof of Borel-Cantelli Lemma

Prove Borel-Cantelli lemma. (<u>2</u>)

$$
\begin{array}{rl}
	\text{if } & \displaystyle
	\sum_{n = 1}^\infty \Pr(A_n) < \infty \\
	\text{then} & \displaystyle \Pr\left(
		\bigcap_{k = 1}^\infty
		\bigcup_{n = k}^\infty
		A_n
	\right) = 0
\end{array}
$$

---

### 1.1. Approach 1: Apply the union bound to find an upper bound

Start by considering the continuity of probability function for $\displaystyle \bigcap_{k = 1}^\infty \bigcup_{n = k}^\infty A_n$. Then, apply the union bound to find an upper bound of $\displaystyle \bigcap_{k = 1}^\infty \bigcup_{n = k}^\infty A_n$.

---

We first define

$$
B_k:= \bigcup_{n=k}^\infty A_n
$$

It is easy to see that $\{B_k\}$ is a decreasing sequence of events.

By axiom 1 and substituting the original formula, we get:

$$
\begin{array}{rrrl}
	0 &\leq& \displaystyle P(\bigcap_{k=1}^\infty \bigcup_{n=k}^\infty A_n) &=& \displaystyle P(\bigcap_{k=1}^\infty B_k) & \text{By definition of } B_k \\
	&&&=& \displaystyle
	P(\lim_{k \to \infty} B_k) & \text{Because } \{B_k\} \text{ is decreasing} \\
	
\end{array}
$$

By [[Continuity of Probability Function]], we can write:

$$
\begin{array}{rl}
	\displaystyle 0 \leq P(\bigcap_{k = 1}^\infty \bigcup_{n=k}^\infty A_n) &=& \displaystyle
	\lim_{k \to \infty} P(B_k) \\
	&=& \displaystyle
	\lim_{k \to \infty} P(\bigcup_{n=k}^\infty A_n) & \text{By definition of } B_k \\
	&\leq& \displaystyle
	\lim_{k \to \infty} \sum_{n=k}^\infty P(A_n) & \text{By union bound} \\
	&=& 0 & \text{By } \displaystyle \sum_{n=1}^\infty P(A_n) < \infty
\end{array}
$$

### 1.2. Show an opposite (equivalent statement)

Show the equivalent statement that "If $\displaystyle P(\bigcap_{k = 1}^\infty \bigcup_{n=k}^\infty A_n) > 0$, then $\displaystyle \sum_{n = 1}^\infty P(A_n) = \infty$". (<u>2</u>)

---

Recall that in [[Combine Union and Intersection with Infinite Sets]], there is the following:

$$
\bigcap_{k = 1}^\infty \bigcup_{n = k}^\infty S_n = \underbrace{
	\{x \in \Omega : x \text{ appears in infinitely many } S_n\}
}_{A}
$$

We call the event on the right side $A$.

We can easily see the following:

$$
\begin{array}{rrl}
	& P(A_n) &\geq& P(A_n \cap A) \\
	\implies & \displaystyle
	\sum_{n=1}^N P(A_n) &\geq& 
	\displaystyle
	\sum_{n=1}^N P(A_n \cap A), & \text{for all }N
\end{array}
$$

Now we only need to show that $\displaystyle \sum_{n=1}^N P(A_n \cap A)$ is $\infty$.

![[Pasted image 20241025191829.png]]

---

# Reference

1. “Borel–Cantelli Lemma.” In Wikipedia, October 17, 2024. https://en.wikipedia.org/w/index.php?title=Borel%E2%80%93Cantelli_lemma&oldid=1251703242.
2. Hsieh, Ping-Chun. “Probability Homework 1: Axioms, Sets, and Conditional Probability,” September 25, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.