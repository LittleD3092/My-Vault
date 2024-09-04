Tag: #probabilistic-robotics 
Previous: [[Environment Interaction of Robots]]
Link: 

[TOC]

---

And there are two types of data stream: (<u>1</u>)

1. **Measurement data**: Provides information about a state of the environment. For example, camera images and range scans. The data at time $t$ will be noted: $$z_t$$And a continuous data stream from $t_1$ to $t_2$ will be noted: $$z_{t_1:t_2} = z_{t_1}, z_{t_1 + 1}, \dots, z_{t_2}$$
2. **Control data**: Provides information about a state change. For example, velocity of the robot. A sequence of control data is denoted: $$u_{t_1:t_2} = u_{t_1}, u_{t_1 + 1}, \dots , u_{t_2}$$

---

# Reference

1. S. Thrun, W. Burgard, and D. Fox, Probabilistic Robotics, 1st edition. The MIT Press, 2005.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.