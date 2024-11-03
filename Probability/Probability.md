Tag: #probabilistic-robotics #probability
Previous: [[Probabilistic Robotics]]
Link: 

[TOC]

---

Let $X$ be a random variable, and $x$ is a possible outcome of $X$. We denote the probability of $X$ having value $x$: (<u>1</u>)

$$p(X = x)$$

# Example

For example, flipping a coin have probability:

$$p(X = \text{"head"}) = p(X = \text{"tail"}) = \frac 1 2$$

# Links

## Lecture 1 - Probability Model

- [[Randomness]]
	- [[Principle of Indifference]]
	- [[Partial Observability]]
- [[Sample Space]] $\Omega$
	- [[Countably Infinite Case]]
	- [[Continuous Case]]
- [[Event]]
- [[Set]]
	- [[Universal Set]] $\Omega$
	- [[Element]]
	- [[Subset]]
	- [[Empty Set]] $\varnothing$
	- [[Complement]] $S^c$
	- [[Union]] $S \cup T$
	- [[Intersection]] $S \cap T$
	- [[Difference]] $S - T$
	- [[Disjoint]]
	- [[Mutually Exclusive]]
- [[Combine Union and Intersection with Infinite Sets]]

## Lecture 2 - Probability Axioms and Continuity of Probability Function

- [[Probability Axioms]]

## Lecture 3 - Continuity of Probability Function and Conditional Probability

- [[Probability Function]]
	- [[Continuity of Probability Function]]
		- [[Increasing Sequence of Events]]
		- [[Decreasing Sequence of Events]]
		- [[Determine Increasing or Decreasing Sequence]]
	- [[Conditional Probability]]
- [[Continuity of Functions]]

## Lecture 4 - Conditional Probability

- [[Conditional Probability]]
	- 3 useful tools:
		- [[Multiplication Rule]]
		- [[Total Probability Theorem]]
		- [[Bayes Rule (Probability)]]

## Lecture 5 - Conditional Probability, Combinatorics, and Random Variables

- Review
	- [[Conditional Probability]]
		- 3 useful tools:
			- [[Multiplication Rule]]
			- [[Total Probability Theorem]]
			- [[Bayes Rule (Probability)]]
- [[Pairwise Independence of Events]]
	- [[Independence of Multiple Events]]
	- [[Conditional Independence]]

## Lecture 6 - Random Variables

- [[Random Variables]]
	- [[Function of a Random Variable]]
	- [[Discrete Random Variables]]
		- [[Cumulative Distribution Function of Discrete Random Variables]]
		- [[Probability Mass Function]]
		- [[Bernoulli Random Variables]]
		- [[Binomial Random Variables]]
	- [[Continuous Random Variables]]
- [[Borel-Cantelli Lemma]]

## Lecture 7 - Discrete Random Variables

- [[Combination]]
- [[Binomial Random Variables]]
- [[Poisson Random Variables]]

## Lecture 8 - Discrete Random Variables, Entropy, and Expected Value

- [[Geometric Random Variables]]

## Lecture 9 - Discrete Random Variables, Entropy, and Expected Value

- [[Discrete Uniform Random Variables]]
- [[Shannon Entropy]]
- [[Expected Value]]
	- [[St Petersburg Paradox]]
	- [[Alternative Expression of Expected Value]]

## Lecture 10 - Expected Value and Moments

- [[Expected Value]]
	- [[St Petersburg Paradox]]
	- [[Alternative Expression of Expected Value]]
	- [[Law of the Unconscious Statistician]]
	- [[Linearity of Expected Values]]
- [[Variance]]

## Lecture 11 - Moments and Continuous Random Variables

- [[Existence of Moments]]
	- [[Riemann Rearrangement Theorem]]
- [[Expected Value and Variance List]]
- [[Probability Density Function]]

## Lecture 12 - Continuous Random Variables

- [[Continuous Random Variables]]
- [[Probability Density Function]]
- [[From CDF to PDF]]
- [[Uniform Random Variables]]
	- [[Inverse Transform Sampling]]
- [[Standard Normal Random Variable]]
	- [[From Standard Normal to Normal]]
- [[Normal Random Variables]]

## Lecture 13 - Continuous Random Variables, Expectation, and Joint Distributions

- [[Normal Random Variables]]
- [[Exponential Random Variables]]

## Lecture 14 - Joint Distributions

- [[Expected Value]]
	- [[St Petersburg Paradox]]
	- [[Alternative Expression of Expected Value]]
	- [[Law of the Unconscious Statistician]]
	- [[Linearity of Expected Values]]
- [[Fubini's Theorem]]
- [[Joint Cumulative Distribution Function]]
	- [[Marginal Cumulative Distribution Function]]
- [[Joint Probability Mass Function]]
	- [[Marginal Probability Mass Function]]

$$
\begin{array}{}
	\begin{array}{}
		\text{Joint PMF} \\
		P(X=x, Y=y)
	\end{array} & \underrightarrow{
		\begin{array}{l}
			\displaystyle P(X=x) = \\ \displaystyle \sum_y P_{XY}(x, y) \\
			\displaystyle P(Y=y) = \\ \displaystyle \sum_{x} P_{XY}(x, y)
		\end{array}
	} &
	\begin{array}{}
		\text{Marginal PMF} \\
		P(X=x), P(Y=y)
	\end{array} \\ \\
	\left.
		\begin{array}{r}
			P(X \leq t, Y \leq u) = \\
			\sum_{
				\begin{array}{}
					x: x \leq t \\
					y: y \leq u
				\end{array}
			} P(X=x, Y=y)
		\end{array}
	\right\downarrow \left\uparrow 
		\begin{array}{l}
			P(X=x, Y=y) = \\
			F_{XY}(x, y) - F_{XY}(x^-, y) \\
			-F_{XY}(x, y^-) + F_{XY}(x^-, y^-)
		\end{array}
	\right. && 
	\left.
		\begin{array}{r}
			F_X(t) = \\
			\sum_{x:x \in t} P(X=x)
		\end{array}
	\right \downarrow
	\left \uparrow
		\begin{array}{l}
		P(X=x) = \\
		F_X(t) - F_X(t^-)
		\end{array}
	\right. \\ \\
	\begin{array}{}
		\text{Joint CDF} \\
		F_{XY}(t, u)
	\end{array} &
	\underrightarrow{
		\begin{array}{}
			F_X(t) = F_{XY} (t, \infty) \\
			F_Y(t) = F_{XY}(\infty, u)
		\end{array}
	} & 
	\begin{array}{}
		\text{Marginal CDF} \\
		F_X(t), F_Y(u)
	\end{array}
\end{array}
$$

- [[Joint Probability Density Function]]
	- [[Marginal Probability Density Function]]

---

# Reference

1. Thrun, Sebastian, et al. Probabilistic Robotics. 1st edition, The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.