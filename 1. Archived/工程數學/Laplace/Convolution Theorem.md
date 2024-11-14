標籤: #工程數學 

---

# Laplace Transform

可以把 [[Convolution]] 轉換成 multiplication: (<u>1</u>)

$$L\{f(t) * g(t)\} = L\{f(t)\}L\{g(t)\} = F(s)G(s)$$

## Example

### 1. Laplace of a convolution

$$L\left\{\int_0^te^{\tau}\sin(t - \tau)d\tau\right\} = L\{e^t * \sin t\} = \frac{1}{s - 1}\frac{1}{s^2 + 1}$$

### 2. Inverse Laplace of multiplication

$$L^{-1}\left\{\frac{1}{(s^2 + k^2)^2}\right\} = \frac{1}{k^2}(\sin kt * \sin kt) = \frac{1}{k^2}\int_0^t \sin k\tau \sin k(t - \tau)d\tau$$

# Independent Random Variable

Let $X, Y$ be two independent discrete random variables with PMF $p_X(x)$ and $p_Y(y)$. Define $Z = X + Y$. Then, the PMF of $Z$ is (<u>2</u>)

$$p_Z(z) = P(Z = z) = \sum_x p_X(x) p_Y(z - x)$$

Let $X, Y$ be two continuous independent random variables with PDF $f_1$ and $f_2$. Define $Z = X + Y$. Then, the PDF of $Z$ is (<u>2</u>)

$$
f_Z(z) = \int_{-\infty}^\infty f_1(x)f_2(z - x)dx
$$

## Examples

### 1. Sum of two Poisson random variables

Let $X \sim \text{Poisson}(\lambda_1, T)$, $Y \sim \text{Poisson}(\lambda_2, T)$, and $Z = X + Y$. What is the PMF of $Z$? (<u>2</u>)

---

$$Z\sim \text{Poisson}(\lambda_1 + \lambda_2, T)$$

---

參考資料:

1. [工程數學 class 22 - properties of laplace transform - youtube](https://youtu.be/46CiHQ3EYeY)
2. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.

---

link:

[[Convolution]]