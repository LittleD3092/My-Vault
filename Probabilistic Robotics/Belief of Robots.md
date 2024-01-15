Tag: #probabilistic-robotics 
Previous: [[Probabilistic Robotics]]
Link: 

[TOC]

---

Because the state of the robot cannot be measured directly, robots have a **belief** about the it's current state. The belief is also a probability distribution:

$$bel(x_t) = p(x_t \vert z_{1:t}, u_{1:t})$$

- $p(x_t\vert z_{1:t}, u_{1:t})$: The probability distribution over the state $x_t$, conditioned on the available data.

Note that the above version measured $z_t$. In some cases, it is useful to calculate a belief without current measure $z_t$:

$$\overline{bel}(x_t) = p(x_t \vert z_{1:t - 1}, u_{1:t})$$

And calculating $bel(x_t)$ from $\overline{bel}(x_t)$ is called **correction** or **measurement update**.

---

# Reference

1. S. Thrun, W. Burgard, and D. Fox, Probabilistic Robotics, 1st edition. The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.