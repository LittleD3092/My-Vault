Tag: #computer-graphics 
Previous: [[Polygonal Shading]]
Link: 

[TOC]

---

**This is different than the [[Phong Reflection Model|Phong reflection model]]**. Phong shading, like [[Gouraud Shading|Gouraud shading]], uses interpolate.

![[Pasted image 20231029140230.png|200]]

The difference of Phong shading and [[Gouraud Shading|Gouraud shading]] is that Phong shading uses interpolate only on normals. Phong shading has the following steps, compared to [[Gouraud Shading|Gouraud shading]]:

|           | Phong shading                                                                                                                            | [[Gouraud Shading\|Gouraud shading]]                                                                |
| --------- | ---------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| procedure | <ol><li>Calculate each vertex's normal. <li>Interpolate normals on edges. <li>Apply Phong reflection model at each potential pixel.</ol> | <ol><li>Find vertex shading.<li>Interpolate through edges.<li>Interpolate through the polygon.</ol> | 

There are several **problems** with Phong shading:

1. **Polygon silhouette**: The edges of the object still have polygons. The shading may deal with each polygon, but the edges are still visible.
![[Pasted image 20231029141037.png|200]]
2. **Perspective distortion**: When doing interpolation on 2D screen, the ratio will be different on 3D object.
3. **Orientation dependence**: Depending on the orientation of view plane, the color of the object is different.
4. **Problems at shared vertices**: The color at T-junction is ambiguous.
5. **Unrepresentative vertex normals**: The normals may be pointing at the same direction, and some complex structures will not be rendered properly.
![[Pasted image 20231029141504.png|200]]

---

# Reference

- 林奕成. “Introduction to Computer Graphics, Ch5 Shading Part 3.” NYCU EC114[GF], October 23, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.