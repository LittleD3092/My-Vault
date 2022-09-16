標籤: #Mechanical-Engineering-Design

---

[TOC]

---

This note is for fragments of knowledge that is too small to form a note itself. You can find some simple keywords here.

# Breakeven Points

Breakeven points is a cost comparison between two possible production methods. For example, there are two ways to manufacture a product, by hand or by machines doing it automatically.

![[breakeven point.png|500]]

As the image above, there is a point where the profit of the automatic method exceeds the method of hand. This point is called a "breakeven point".

# Stress and Strength 

| Stress                                                                                                                                                      | Strength                                                                                                                                                          |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Represent a force that is applied to an object, often represented using pressure $(N/m^2)$ <br> $\sigma$ for [[Normal Stress]], $\tau$ for [[Shear Stress]] | A property of a material, <br> ex. ultimate strength, yield strength <br> Often represented using $S$ with a subscript. For example, yield strength will be $S_y$ |

# Uncertainty

Their are many factors that cause the strength of a material to decrease, like corrosion. The "uncertainty" of a material means that the strength of a material is decreasing.

To prevent uncertainty, we have two methods:

1. Stochastic Method: Use trial and error, record the statistics. With a lot of samples, say 1000, we will find out the uncertainty of the material.
2. Deterministic Method: While we have a yield stress, we can determine a stress using [[Factor of Safety(FoS)]].

$$n_d = \frac{\text{loss-of-function param}}{\text{max allowable param}}$$

# Reliability

Opposite to [[#Uncertainty]], reliability means the probability that an element will not fail in use. This value is often represented in $R$.

When we are determining the reliability for a series system with a lot of components, the reliability of the system is the product of each component's reliability.

$$R = \prod_{i = 1}^{n} R_i, \quad R_i\text{ is the reliability of each component. }$$

We should avoid using too many components while designing a series system, because the more components you use, the less reliability you got.

# [[Design Process]]

![[Design Process]]

# Resilience

Resilience means the capacity of a material to absorb energy within its elastic range. The resilience of a material is represented as modulus of resilience, $u_R$.

- $u_R$ is the energy absorbed per unit volume without permanent deformation.
- $u_R$ equals the area of the gray part of the following diagram:

![[resilience area - mechanical engineering design basics.png|250]]

- $u_R$ is calculated using the area before $el$ by definition. But the elastic point is not too easy to measure, therefore yield point $y$ is often used.

---

參考資料:

機械設計原理上課

---

link:

