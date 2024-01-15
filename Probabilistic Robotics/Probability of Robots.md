Tag: #probabilistic-robotics 
Previous: [[Probabilistic Robotics]]
Link: [[Data of Robots]]

[TOC]

---

The probability distribution of the state $x_t$ at time $t$ is: (<u>1</u>)

$$p(x_t \vert x_{0: t-1}, z_{1:t - 1}, u_{1:t})$$

- $x_{0:t - 1}$: Previous sequence of states.
- $z_{1:t - 1}$: Previous sequence of measurement data.
- $u_{1:t}$: Previous sequence of control data. Note that the robot executes a control action first.

If the state $x_t$ is **complete**, it contains all variables of previous control actions and measurements. Then the above probability distribution can be expressed by:

$$p(x_t \vert x_{0: t-1}, z_{1:t - 1}, u_{1:t}) = p(x_t \vert x_{t - 1}, u_t)$$

Also, the model of generating the measurements can be written as follows if state $x_t$ is **complete**:

$$p(z_t\vert x_{0:t}, z_{1:t - 1}, u_{1:t}) = p(z_t \vert x_t)$$

The 2 probability distributions can be combined to describe a dynamical stochastic system:

$$\left\{
\begin{array}{l}
	p(x_{t} \vert x_{t - 1}, u_t) & \text{state transition probability} \\
	p(z_t \vert x_t) & \text{measurement probability}
\end{array}
\right.$$

---

# Reference

1. S. Thrun, W. Burgard, and D. Fox, Probabilistic Robotics, 1st edition. The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.