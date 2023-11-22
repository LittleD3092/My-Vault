Tag: #ROS 
Previous: [[ROS Packages for Locolization]]
Link: 

[TOC]

---

`tf` is a ros package that is used to handle transformation. For example, the lidar and the base may need a transformation: (<u>1</u>)

![[Pasted image 20231120182137.png]]

`tf` will use a [[Tree|tree]] to manage the transformation: (<u>1</u>)

![[Pasted image 20231120182519.png]]

- Each node represents a coordinate.
- Each link represents a transformation.

---

# Reference

1. “Navigation/Tutorials/RobotSetup/TF - ROS Wiki.” Accessed November 20, 2023. http://wiki.ros.org/navigation/Tutorials/RobotSetup/TF.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.