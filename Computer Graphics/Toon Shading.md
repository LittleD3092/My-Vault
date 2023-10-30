Tag: #computer-graphics 
Previous: [[GPU Programmable Components]]
Link: [[Vertex Shader]], [[Fragment Shader]]

[TOC]

---

Toon shading has the following effect: (<u>1</u>)

![[Pasted image 20231030133325.png|200]]

Toon shading can be achieved by [[Phong Shading|Phong shading]] with discrete intensity. An example code: (<u>1</u>)

```cpp
// vertex shader
out vec3 vnormal;
void main () {
	vnormal = gl_NormalMatrix* gl_Normal;
	gl_Position = ftransform();
}

// fragment shader
in vec3 vnormal;
out vec4 FragColor;
void main() {
	float intensity;
	vec4 color;
	vec3 n = normalize(vnormal);
	intensity = dot(vec3(gl_LightSource[0].position), n);
	if (intensity > 0.95) 
		color = vec4(1.0, 0.5, 0.5, 1.0);
	else if (intensity > 0.95)
		color = vec4(0.6, 0.3, 0.3, 1.0);
	else if (intensity > 0.5)
		color = vec4(0.4, 0.2, 0.2, 1.0);
	else
		color = vec4(0.2, 0.1, 0.1, 1.0);
	FragColor = color;
}
```

---

# Reference

1. 林奕成. “Introduction to Computer Graphics, Chapter 6: GPU and Shaders.” NYCU EC114[GF], October 30, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.