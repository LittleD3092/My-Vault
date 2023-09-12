Tag: #ROS 
Previous: 
Link: 

[TOC]

---

# Import Solidworks Models into Gazebo

## Check "Feasible"

Before you import a model into gazebo, make sure your model is **feasible**.

By "feasible", we mean:

- Only contain:
	- revolute
	- continuous
	- prismatic
	- free and fixed joints
- Do not contain N-bar linkages where a series of links connect back to a link previously in chain.

## File Type: URDF and SDF

| URDF              | SDF                       |
| ----------------- | ------------------------- |
| Support ROS tools | Used by Gazebo simulation |
| Has less details  | Includes more details     | 

### File Type: URDF

- URDF stands for "**universal robot description format**".
- **Xml-like** file type.
- Supported for ROS tools.
- A **tree** structure.
	- Parent may be a chassis.
	- Children may be wheels and arms.
	- Children are connected to parent through **joints**.
- Describes how your system moves and interact.

> Tree limitations:
> Because of the tree structure, there are limitations to the models.
> For example, a 4-bar linkage cannot be modelled by tree structure.

### File Type: SDF

- Stands for **Simulator Description Format**.
- Has better capabilities compared to URDF.
- Used by Gazebo for simulation.
- Includes more details:
	- Friction.
	- Damping.
	- Environment properties like light.

## Concepts

- **Coordinate/origin**: A reference point to understand motion.
- **Axes**: A reference for motion.
	- **Revolute** and **continuous** joints rotate around axes.
	- **Prismatic** joints translate along axes.
- The plugin only supports four kinds of links:
	- Revolute
	- Prismatic
	- Continuous
	- Fixed

### Accelerate Simulation

![[Pasted image 20230620161852.png]]

- Gazebo checks every faces for collision.
- Therefore, we wish to minimize the number of faces when modelling.
- It is ideal to have seperate models for visualizing and simulating, like the figure above.

For collisional model, there are few guidelines:

1. Group rigid body together.
	- Motors can be grouped with the arm or chassis that it is attached to.
2. Use only what you need.
	- Only outside surfaces of a model is required.
	- A hollow closed box can be approximated by a solid box, to ignore internal faces.
3. Basic shapes work the best.
	- Use cylinder instead of wheels.
	- Use boxes.

---

# Reference

[WPI-Robotics-SolidWorks-to-Gazebo.pdf](https://blogs.solidworks.com/teacher/wp-content/uploads/sites/3/WPI-Robotics-SolidWorks-to-Gazebo.pdf)

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.