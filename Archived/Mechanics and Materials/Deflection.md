標籤: #Mechanics-and-Materials 

---

# 證明

From [[Moment Curvature Relationship of Bending]]

$$\frac{ 1 }{ \rho } = \frac{ M }{ EI }$$

Use Curvature Equation:

$$\frac{ 1 }{ \rho } = \frac{ (\frac{ d^2y }{ dx^2 }) }{ \left[1 + (\frac{ dy }{ dx })^2\right]^{ \frac{ 3 }{ 2 } } }$$

assume small [[Deformation|deformations]] $(\frac{ dy }{ dx })^2 << 1$

$$\implies\frac{ 1 }{ \rho } \approx \frac{ d^2y }{ dx^2 }$$

代回 [[Moment Curvature Relationship of Bending]]

$$\underline{ EI\frac{ d^2y }{ dx^2 } = M(x) }_{ \# }$$

$$\implies V = \frac{ dM }{ dx } = EI\frac{ d^3y }{ dx^3 }$$

$$\text{ slope } = \frac{ dy }{ dx } = \int\frac{ M }{ EI }dx$$

$$\text{ deflection } = y = \int\int\frac{ M }{ EI }dxdx$$

# [[Singularity Functions]]

用來表示受力情況與 moment 的位置，方便計算，詳見[[Singularity Functions]]

---

參考資料:

coursera mechanics and materials

---

link:

