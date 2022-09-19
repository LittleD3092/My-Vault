標籤: #DataStructure #algorithm 

---

[TOC]

---

# [[Asymptotic Notation]] of Recursion Functions

To solve [[#Big-O Notation]] of a recursion function, we have two methods:

1. [[#Substitution Method]]
2. [[#Recursion Tree Method]]

The first one is used to prove your answer, and the second one is used to guess an answer. Therefore, you are probably going to use both of them.

The following example is the process of solving [[#Big-O Notation]] for [[Merge Sort]] algorithm. Merge sort needs at most 

$$T(n) = T(\lfloor n / 2 \rfloor) + T(\lceil n / 2 \rceil) + c_1n$$

operations where $T(1) = c_2$.

## Substitution Method

Assume we guessed that 

$$T(n) \leq dn\log_2 n + en$$

for some constant $d > 0$, $e > 0$ in the [[#Recursion Tree Method]] section.

We use mathematical induction to prove that this guess is correct:

For $n = 1$, 

$$T(1) = c_2 \leq d \log_2 1 + e$$

if we pick $e \geq c_2$.

Suppose

$$T(n) \leq dn \log_2 n + en$$

for every $n < k$.

For $n = k$, 

$$T(k) = 
T(\lfloor k / 2 \rfloor) + 
T(\lceil k / 2 \rceil) + c_1k$$

$$\leq 2T(k / 2) + c_1k$$

$$\leq 2(d \cdot k / 2 \cdot \log_2(k / 2) + 
e \cdot k / 2) + c_1k$$

$$ = dk \cdot \log_2(k / 2) + ek + c_1 k$$

$$ = dk \cdot \log_2 k - dk + ek + c_1k$$

$$\leq dk \cdot \log_2 k + ek \quad(\text{if we pick } d \geq c_1)$$

By induction on $k$, our guess is correct. Thus, 

$$T(n) = O(n \log_2 n)$$

## Recursion Tree Method

In this section, we are going to use recursion tree method to take a guess of the [[Merge Sort]]'s [[#Big-O Notation]].

We simply need a guess, therefore we may drop the floor and the ceiling functions and ignore the constants. We get:

$$T(n) = 
\left\{
	\begin{array}{}
		2T(n / 2) + n & \text{if } n > 1 \\
		1             & \text{if } n = 1
	\end{array}
\right.$$

Based on the function above, we draw the following tree:

```mermaid
flowchart TD

Tn["T(n)"]

Tn2_1["T(n/2)"]
Tn2_2["T(n/2)"]

Tn4_1["T(n/4)"]
Tn4_2["T(n/4)"]
Tn4_3["T(n/4)"]
Tn4_4["T(n/4)"]

Tn --- Tn2_1
Tn --- Tn2_2

Tn2_1 --- Tn4_1
Tn2_1 --- Tn4_2
Tn2_2 --- Tn4_3
Tn2_2 --- Tn4_4
```

Each node has an approx value:

| node       | approx value |
| ---------- | ------------ |
| $T(n)$     | $n$          |
| $T(n / 2)$ | $n / 2$      |
| $T(n / 4)$ | $n / 4$      | 

The tree has a depth of $\log_2 n$. Each layer takes $n$ time, therefore the toral cost is $O(n\log_2 n)$.

---

參考資料:



---

link:

