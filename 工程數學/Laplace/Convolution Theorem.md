標籤: #工程數學 

---

$$L\{f(t) * g(t)\} = L\{f(t)\}L\{g(t)\} = F(s)G(s)$$
可以把 [[Convolution]] 轉換成 multiplication

# Example

## 1

$$L\left\{\int_0^te^{\tau}\sin(t - \tau)d\tau\right\} = L\{e^t * \sin t\} = \frac{1}{s - 1}\frac{1}{s^2 + 1}$$

## 2

$$L^{-1}\left\{\frac{1}{(s^2 + k^2)^2}\right\} = \frac{1}{k^2}(\sin kt * \sin kt) = \frac{1}{k^2}\int_0^t \sin k\tau \sin k(t - \tau)d\tau$$

---

參考資料:

[工程數學 class 22 - properties of laplace transform - youtube](https://youtu.be/46CiHQ3EYeY)

---

link:

[[Convolution]]