Tag: #network-systems-capstone #probability 
Previous: [[Entropy Detection Method]] [[Probability]]
Link: 

---

Shannon entropy is the bits needed to represent the uncertainty of a random variable. See the first example. (<u>2</u>)

Shannon entropy is the measure of uncertainty using a random variable $X$. It has the following formula: (<u>1</u>)

$$H(X) = -\sum_i P(x_i)\log_b P(x_i)$$

- The formula above is for finite samples.
- $H(X)$: The Shannon entropy of random variable $X$.
- $P(x_i)$: The probability of $X = x_i$.
- $b$: Can be $2, 10$ or $e$, depending on the resulting unit of entropy. For $2$, the unit is bits.

# Examples

## 1. Measuring "Information"

Suppose $X$ is a discrete random variable with PMF:

$$
p(x) = \left\{
    \begin{array}{ll}
        1/2, & \text{if } x = 100 \\
        1/4, & \text{if } x = 200 \\
        1/4, & \text{if } x = 300 \\
        0, & \text{otherwise}
    \end{array}
\right.
$$

On aveerage, how many bits do we need to store the outcome of $X$? (<u>2</u>)

---

If we use a total of 2 bits, and we represent $100, 200, 300$ as $0, 01, 10$, respectively, we can store the outcome of $X$.

The average number of bits needed to store the outcome of $X$ will be:

$$
\frac{1}{2} \times 1 + \frac{1}{4} \times 2 + \frac{1}{4} \times 2 = 1.5
$$

> Why don't we use $0, 1, 10$ to represent $100, 200, 300$? This is because $1$ and $10$ have the same prefix, and Shannon entropy is about prefix-free encoding.

Now try calculating with the Shannon entropy:

$$
\begin{array}{rl}
    H(X) &=& \displaystyle -\sum_i p(x_i)\log_2 p(x_i) \\
    &=& \displaystyle -\left(
        \frac{1}{2}\log_2\frac{1}{2} + \frac{1}{4}\log_2\frac{1}{4} + 
        \frac{1}{4}\log_2\frac{1}{4}
    \right) \\
    &=& 1.5
\end{array}
$$

---

# Reference

1. Li, Liying, Jianying Zhou, and Ning Xiao. “DDoS Attack Detection Algorithms Based on Entropy Computing.” In Information and Communications Security, edited by Sihan Qing, Hideki Imai, and Guilin Wang, 4861:452–66. Lecture Notes in Computer Science. Berlin, Heidelberg: Springer Berlin Heidelberg, 2007. https://doi.org/10.1007/978-3-540-77048-0_35.
2. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.