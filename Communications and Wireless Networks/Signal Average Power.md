Tag: #communications-and-wireless-networks 
Previous: [[Communications and Wireless Networks]]
Link: 

---

Signal average power is calculated by: (<u>1</u>)

1. Square the amplitude of a complex signal.
2. Average it.
3. Take square root.

$$\text{Signal average power} = 
\sqrt{
	E[\vert \text{Signal} \vert^2]
}$$

# Example

Consider a complex random variable $a+bi$ with both $a$ and $b$ following the complex Gaussian normal distribution $\mathcal N(0,1)$. What is the average power of $a+bi$?

---

This can be calculated by: (<u>2</u>)

$$
\begin{array}{l}
	\sqrt{
		E\left[
			\left\vert 
				a + bi 
			\right\vert^2
		\right]
	} &=& 
	\sqrt{
		E\left[
			a^2 + b^2
		\right]
	} \\
	&=& 
	\sqrt{
		E[a^2] + E[b^2]
	} \\
	&=& \sqrt{
		Var(a) + Var(b)
	} \\
	&=& \sqrt{1 + 1} \\
	&=& \sqrt 2
\end{array}
$$

---

# Reference

1. “Signal average power (complex signal),” Physics Forums: Science Discussion, Homework Help, Articles. Accessed: Mar. 11, 2024. [Online]. Available: https://www.physicsforums.com/threads/signal-average-power-complex-signal.301249/
2. ChatGPT, “Consider a complex random variable a+bi with both a and b following the complex Gaussian normal distribution N(0,1). What is the average power of a+bi?” Accessed: Mar. 11, 2024. [Online]. Available: https://chat.openai.com

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.