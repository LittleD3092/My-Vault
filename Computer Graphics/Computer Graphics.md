Tag: #computer-graphics 
Previous: 
Link: 

[TOC]

---

# Chapter 1: Graphics Systems

- [[Pinhole Camera]]
- A realistic 3D view requires:
	- 3D model
	- Perspective
	- Hidden surface removal
	- Shading
	- Shadow
	- Textures

# Chapter 2: Transformations

- [[Transformation Matrix]]
- [[Translation]]
- [[Rotation]]
- [[Scaling]]
- [[Reflection]]
- [[Inverse]]
- [[Shear]]
- [[Hierarchical Structure]]

# Chapter 3: Projection

- Common kinds of projections:

| Parallel Projection                  | Perspective Projection               | Orthographic Projection              |
| ------------------------------------ | ------------------------------------ | ------------------------------------ |
| ![[Pasted image 20231016135900.png]] | ![[Pasted image 20231016135911.png]] | ![[Pasted image 20231016135935.png]] | 

- [[Computer Viewing]]

# Chapter 4: Clipping

- [[Clipping]]
	- [[Viewing Volume]]
		- [[Orthogonal Viewing Volume]]
		- [[Perspective Viewing Volume]]
	- [[Cohen-Sutherland Algorithm]]
	- [[Polygon Clipping]]
		- [[Tessellation and Convexity]]
		- [[Sutherland-Hodgman Algorithm]]
		- [[Cohen-Sutherland Algorithm#Cohen-Sutherland Method in 3D]]

# Chapter 5: Shading

- [[Shading]]
	- [[Global Illumination]]
	- [[Local Illumination]]
	- [[Rendering Equation]]
	- [[Phong Reflection Model]]
		- [[Ambient Component of Phong Reflection Model|Ambient component]]
		- [[Diffuse Component of Phong Reflection Model|Diffuse component]]
		- [[Specular Component of Phong Reflection Model|Specular component]]
			- [[Shininess Coefficient of Phong Reflection Model|Shininess coefficient]]
	- [[Polygonal Shading]]
		- [[Flat Shading]]
			- [[Flat Shading and Fixed Pipeline Acceleration]]
		- [[Gouraud Shading]]
			- [[Gouraud Shading and Fixed Pipeline Acceleration]]
		- [[Phong Shading]]
			- [[Phong Shading and Fixed Pipeline Acceleration]]
- [[Introduction to Computer Graphics HW2]]

# Chapter 6: GPU and Shaders

- [[GPU]]
	- [[3Dfx Voodoo]]
	- [[GeForce 7500]]
	- [[GeForce FX]]
	- [[GPU Programmable Components]]
		- [[Shader]]
			- [[Vertex Shader]]
			- [[Fragment Shader]]
				- [[Bump Mapping]]
			- [[Geometry Shader]]
				- [[Why Single Pipeline can Handle Multiple Projections]]
			- [[Create Shader in OpenGL]]
				- [[Create Shader Function for Creating Shader in OpenGL]]
				- [[Create Program Function for Creating Shader in OpenGL]]
		- [[GLSL Pipeline]]
			- [[GLSL Pipeline with Geometry Shader]]
		- [[Toon Shading]]
- [[Introduction to Computer Graphics HW3]]

# Chapter 7: Rasterization

- [[Rasterization]]
	- [[Line Drawing Algorithms]]
		- [[Digital Differential Analyzer]]
			- [[Digital Differential Analyzer with Symmetry]]
		- [[Bresenham's Algorithm]]
	- [[Circle Drawing Algorithm]]
		- [[Midpoint Circle Algorithm]]
	- [[Polygon Filling]]
		- [[Odd-even Rule for Polygon Filling]]
		- [[Non-zero Winding Rule for Polygon Filling]]
		- [[Scanning Lines for Polygon Filling]]

# Chapter 8: Hidden Surface Removal

- [[Hidden Surface Removal]]
	- [[Back-face Removal]]
	- [[Pairwise Testing for Hidden Surface Removal]]
	- [[Painter's Algorithm]]
	- [[Depth Sort]]
	- [[Image Space Approach]]
	- [[Scan-Line Algorithm]]
	- [[Z-Buffer Algorithm]]
		- [[Z-Buffer]]
	- [[Space Partitioning]]
		- [[Octree]]
		- [[BSP Tree]]

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading.” NYCU EC114[GF], October 16, 2023.
- 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 2.” NYCU EC114[GF], October 18, 2023.
- 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 3.” NYCU EC114[GF], October 23, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.