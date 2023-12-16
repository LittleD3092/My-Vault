- 學號：109611066
- 姓名：吳典謀

# 1. TODO Parts in main

## 1.1. Create shaders and programs for each approach

As in HW2, there are functions `createShader` and `createProgram` to create the programs for each approach. The only difference in this assignment is that the function can handle geometry shaders too. The functions `createShader` and `createProgram` have following definitions:

```c++
// Create a shader based on given filename and type.
// filename: A c string specifying the shader file "shader.vert", "shader.frag", or "shader.geom"
// type: The type of the shader. Can be "vert", "frag", or "geom" for vertex shader, fragment shader or geometry shader.
unsigned int createShader(const char* filename, const char* type);

// Create a program based on given shaders.
unsigned int createProgram(unsigned int vertexShader, unsigned int geometryShader, unsigned int fragmentShader);
```

Using the two functions above, we can create the program for each render effect. I want to call `glUseProgram` in the `while` loop, therefore it is not included in this part.

```c++
/* TODO: Create vertex shader, geometry shader( for flat shading ),fragment shader, shader program for each shading approach 
 * Hint:
 *       createShader, createProgram, glUseProgram
 * Note:
 *       Blinn-Phong shading: "Blinn-Phong.vert", "Blinn-Phong.frag"
 *       Gouraud shading: "Gouraud.vert", "Gouraud.frag"
 *		 Toon shading: "Toon.vert", "Toon.frag"
 *       Flat shading: "Flat.vert", "Flat.geom", "Flat.frag"
 *		 Border effect : "Border.vert", "Border.frag"
 *		 Dissolve effect : "Dissolve.vert", "Dissolve.frag"
 */
// Blinn-Phong shading
unsigned int blinnPhongVert = createShader("Blinn-Phong.vert", "vert");
unsigned int blinnPhongFrag = createShader("Blinn-Phong.frag", "frag");
unsigned int blinnPhongProgram = createProgram(blinnPhongVert, 0, blinnPhongFrag);

// Gouraud shading
unsigned int gouraudVert = createShader("Gouraud.vert", "vert");
unsigned int gouraudFrag = createShader("Gouraud.frag", "frag");
unsigned int gouraudProgram = createProgram(gouraudVert, 0, gouraudFrag);

// Toon shading
unsigned int toonVert = createShader("Toon.vert", "vert");
unsigned int toonFrag = createShader("Toon.frag", "frag");
unsigned int toonProgram = createProgram(toonVert, 0, toonFrag);

// Flat shading
unsigned int flatVert = createShader("Flat.vert", "vert");
unsigned int flatGeom = createShader("Flat.geom", "geom");
unsigned int flatFrag = createShader("Flat.frag", "frag");
unsigned int flatProgram = createProgram(flatVert, flatGeom, flatFrag);

// Border effect
unsigned int borderVert = createShader("Border.vert", "vert");
unsigned int borderFrag = createShader("Border.frag", "frag");
unsigned int borderProgram = createProgram(borderVert, 0, borderFrag);

// Dissolve effect
unsigned int dissolveVert = createShader("Dissolve.vert", "vert");
unsigned int dissolveFrag = createShader("Dissolve.frag", "frag");
unsigned int dissolveProgram = createProgram(dissolveVert, 0, dissolveFrag);
```

## 1.2. Pass variables to shader through uniform

To choose the correct shading program, I declared a global variable `shadingType`:

```c++
enum class ShadingType {
	BLINN_PHONG = 1,
	GOURAUD = 2,
	FLAT = 3,
	TOON = 4,
	BORDER = 5,
	DISSOLVE = 6
};
ShadingType shadingType = ShadingType::BLINN_PHONG;
```

Using this variable, I can change the `shadingType` from the function `keyCallback`. By reading the current `shadingType`, I can choose the correct program in the `switch` statement, and pass the uniform variables.

```c++
/* TODO: Create all variable and pass them to shaders through uniform
 * Hint:
 *		glUniformMatrix4fv, glUniform3fv, glUniform1f
 */
GLint program;
switch (shadingType) {
case ShadingType::BLINN_PHONG:
	program = blinnPhongProgram;
	break;
case ShadingType::GOURAUD:
	program = gouraudProgram;
	break;
case ShadingType::FLAT:
	program = flatProgram;
	break;
case ShadingType::TOON:
	program = toonProgram;
	break;
case ShadingType::BORDER:
	program = borderProgram;
	break;
case ShadingType::DISSOLVE:
	program = dissolveProgram;
	break;
}
glUseProgram(program);

glUniformMatrix4fv(glGetUniformLocation(program, "perspective"), 1, GL_FALSE, glm::value_ptr(perspective));
glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, glm::value_ptr(model));

glUniform3fv(glGetUniformLocation(program, "material.ambient"), 1, glm::value_ptr(material.ambient));
glUniform3fv(glGetUniformLocation(program, "material.diffuse"), 1, glm::value_ptr(material.diffuse));
glUniform3fv(glGetUniformLocation(program, "material.specular"), 1, glm::value_ptr(material.specular));
glUniform1f(glGetUniformLocation(program, "material.shininess"), material.shininess);

glUniform3fv(glGetUniformLocation(program, "light.ambient"), 1, glm::value_ptr(light.ambient));
glUniform3fv(glGetUniformLocation(program, "light.diffuse"), 1, glm::value_ptr(light.diffuse));
glUniform3fv(glGetUniformLocation(program, "light.specular"), 1, glm::value_ptr(light.specular));
glUniform3fv(glGetUniformLocation(program, "light.position"), 1, glm::value_ptr(light.position));

glUniform3fv(glGetUniformLocation(program, "cameraPos"), 1, glm::value_ptr(cameraPos));
```

## 1.3. Key callback

Using the enumerator `shadingType` declared in [[#1.2. Pass variables to shader through uniform]], the callback function is easy to implement:

```c++
/* TODO: Key callback
 *    1. Press '1' : switch to blinn-phong shading program
 *    2. Press '2' : switch to gouraud shading program
 *    3. Press '3' : switch to flat shading program
 *    4. Press '4' : switch to toon shading program
 */
 /* Advanced
  *   1. Press '5' : switch to border effect program
  *	  2. Press '6' : switch to dissolve effect program
  */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		rotating = !rotating;
		cout << "KEY SPACE PRESSED\n";
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
		shadingType = ShadingType::BLINN_PHONG;
		cout << "KEY 1 PRESSED, SWITCH TO BLINN-PHONG\n";
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
		shadingType = ShadingType::GOURAUD;
		cout << "KEY 2 PRESSED, SWITCH TO GOURAUD\n";
	}
	if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
		shadingType = ShadingType::FLAT;
		cout << "KEY 3 PRESSED, SWITCH TO FLAT\n";
	}
	if (key == GLFW_KEY_4 && action == GLFW_PRESS) {
		shadingType = ShadingType::TOON;
		cout << "KEY 4 PRESSED, SWITCH TO TOON\n";
	}
	if (key == GLFW_KEY_5 && action == GLFW_PRESS) {
		shadingType = ShadingType::BORDER;
		cout << "KEY 5 PRESSED, SWITCH TO BORDER\n";
	}
	if (key == GLFW_KEY_6 && action == GLFW_PRESS) {
		shadingType = ShadingType::DISSOLVE;
		cout << "KEY 6 PRESSED, SWITCH TO DISSOLVE\n";
	}
		
}
```

# 2. Blinn-Phong

## 2.1. Vertex Shader

```c++
#version 330 core

// TODO:
// implement Blinn-Phong shading
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;  
    TexCoords = aTexCoords;
    
    gl_Position = perspective * view * vec4(FragPos, 1.0);
}
```

- `model`: The transform matrix of the object.
- `aPos`: The coordinate of the vertex in the model file.
- `FragPos`: The world position of the vertex. Calculate using the formula below:

$$\text{FragPos} = \text{model} \times \text{aPos}$$

- `Normal`: The normals `aNormal` is transformed using the `model` matrix (removed translation).
- `TexCoords`: The texture coordinates are passed directly, since texture is not processed in vertex shader.
- `gl_Position`: The position for rasterize. This is set using the model-view-projection matrix.

$$\text{gl\_Position} = \text{perspective} \times \text{view} \times \text{model} \times \left[ \begin{array}{} \text{aPos} & 0 \\ 0 & 1 \end{array} \right]$$

## 2.2. Fragment Shader

```c++
#version 330 core

// TODO:
// implement Blinn-Phong shading

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

struct Material 
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light 
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
uniform vec3 cameraPos;
uniform sampler2D textureSampler;

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.ambient;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // specular
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(norm, halfwayDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    result = result * texture(textureSampler, TexCoords).rgb;
    FragColor = vec4(result, 1.0);
}
```

The Phong reflection model has the following formula:

$$
\begin{array}{l}
	{\bf l} &=& {\bf l}_\text{ambient} + {\bf l}_\text{diffuse} + {\bf l}_\text{specular} \\
	&=& {\bf K}_a{\bf l}_a + {\bf K}_{d}{\bf l}_{d}({\bf l}\cdot {\bf n}) + {\bf K}_s{\bf l}_s({\bf v} \cdot {\bf r})^\alpha
\end{array}
$$

Blinn-Phong shading replaces the ${\bf v} \cdot {\bf r}$ with ${\bf n} \cdot {\bf h}$, where $\bf h$ is the halfway vector:

$${\bf h} = \frac{{\bf l + {\bf v}}}{\vert\vert {\bf l} + {\bf v} \vert\vert}$$

- ${\bf l}$: The direction of light. `lightDir` in the code.
- $\bf v$: The direction of viewer. `viewDir` in the code.
- $\bf h$: The halfway vector. `halfwayDir` in the code.

Therefore, the Blinn-Phong shading has the following formula:

$$\begin{array}{l}
	{\bf l} &=& {\bf l}_\text{ambient} + {\bf l}_\text{diffuse} + {\bf l}_\text{specular} \\
	&=& {\bf K}_a{\bf l}_a + {\bf K}_{d}{\bf l}_{d}({\bf l}\cdot {\bf n}) + {\bf K}_s{\bf l}_s({\bf h} \cdot {\bf n})^\alpha
\end{array}$$

- ${\bf l}_{\rm ambient}$: Variable `ambient` in the code.
- ${\bf l}_{\rm diffuse}$: Variable `diffuse` in the code.
- ${\bf l}_{\rm specular}$: Variable `specular` in the code.
- ${\bf K}_a, {\bf K}_d, {\bf K}_s$: Variable `material` in the code.
- ${\bf l}_a, {\bf l}_d, {\bf l}_s$: Variable `light` in the code.
- $\bf l$: Variable `lightDir` in the code.
- ${\bf n}$: Variable `norm` in the code.
- $\alpha$: Member variable `material.shininess` in the code.

# 3. Gouraud

## 3.1. Vertex Shader

The vertex shader of Gouraud shading is the same as [[#2. Blinn-Phong]].

## 3.2. Fragment Shader

The fragment shader is similar to [[#2. Blinn-Phong]], but it uses the original Phong reflection model.

```c++
#version 330 core

// TODO:
// Implement Gouraud shading

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

struct Material 
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light 
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
uniform vec3 cameraPos;
uniform sampler2D textureSampler;

void main()
{
    // ambient
    vec3 ambient = light.ambient * material.ambient;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;
    result = result * texture(textureSampler, TexCoords).rgb;
    FragColor = vec4(result, 1.0);
}
```

Note that the calculation of specular is different, using the following formula:

$${\bf l}_{\rm specular} = {\bf K}_s{\bf l}_s({\bf v} \cdot {\bf r})^\alpha$$

- ${\bf l}_{\rm specular}$: Specular component `specular`.
- ${\bf K}_s$: Specular component of material `material.specular`.
- ${\bf l}_s$: Specular component of light `light.specular`.
- ${\bf v}$: Viewer direction `viewDir`.
- ${\bf r}$: Reflect direction `reflectDir`.

# 4. Toon shading

## 4.1. Vertex shader

The vertex shader of toon shading is the same as [[#2. Blinn-Phong]].

## 4.2. Fragment shader

The fragment shader calculates the dot product of normal vector `n` and light direction `l`. The result is the intensity `intensity`, and is used to determine the color `FragColor`:

```c++
#version 330 core

// TODO:
// Implement Toon shading
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

out vec4 FragColor;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;

void main()
{
    float intensity;
    vec3 n = normalize(Normal);
    vec3 l = normalize(light.position - FragPos);
    intensity = max(dot(n, l), 0.0);

    if(intensity > 0.95)
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    else if(intensity > 0.75)
        FragColor = vec4(0.9, 0.8, 0.7, 1.0);
    else if(intensity > 0.5)
        FragColor = vec4(0.5, 0.3, 0.3, 1.0);
    else
        FragColor = vec4(0.2, 0.1, 0.1, 1.0);
}
```

# 5. Border effect

## 5.1. Vertex shader

The vertex shader of border effect is the same as [[#2. Blinn-Phong]].

## 5.2. Fragment shader

The fragment shader of border effect uses the angle between the normal `normal` and the view vector `viewDir`. I use dot product to calculate the ratio of texture color `textureColor` and border color `borderColor`. The result color is calculated using these colors and the ratio, using `mix` function.

```c++
#version 330 core

// Advanced:
// Implement Border effect

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 cameraPos;
uniform sampler2D textureSampler;

void main()
{
    vec3 normal = normalize(Normal);
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec4 borderColor = vec4(1.0, 1.0, 1.0, 1.0);

    float ratio = 1 - max(dot(normal, viewDir), 0);
    vec4 textureColor = texture(textureSampler, TexCoords);
    FragColor = mix(textureColor, borderColor, ratio);
}
```

# 6. Dissolve effect

## 6.1. Vertex shader

The vertex shader of dissolve effect is the same as [[#2. Blinn-Phong]].

## 6.2. Fragment shader

Since the `TexCoords` is passed, and it is normalized, it is convenient to use it as a indicator of the position of the pixel.

I use `TexCoords.x` as the indicator, and compare it with `dissolveFactor`. If `TexCoords.x` is smaller than `dissolveFactor`, it is given a transparent color.

```c++
#version 330 core

// Advanced:
// Implement Dissolve effect

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D textureSampler;
uniform float dissolveFactor;

void main()
{
    vec4 texColor = texture(textureSampler, TexCoords);
    if(TexCoords.x < dissolveFactor)
        FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    else
        FragColor = texColor;
}
```

# 7. Problems

## 7.1. Object.h not detected

In the source file `main.cpp`, the include:

```c++
#include "Object.h"
```

Is not recognized. I find out that the file is `object.h` in the `include` folder, and the correct include is:

```c++
#include "object.h"
```

## 7.2. Assertion failed

![[Pasted image 20231215232055.png]]

When execute the program, an assertion is triggered about reading the file `Blinn-Phong.vert`.

### 7.2.1. Solution 1: Using more explicit path

Since this file name is the first call of `createShader` function, I suspect that I need to specify the relative path of `main.cpp` to the path of shader files.

Therefore, I modified the `createShader` function to append `shaders/` before each filename:

```c++
char* filePath = new char[100];
strcpy(filePath, "shaders/");
strcat(filePath, filename);
FILE* fp = fopen(filePath, "rb");
```

This solves the issue.

## 7.3. Shader compilation failed

![[Pasted image 20231215233611.png]]

The first compile error is the name of `viewPos` should be `cameraPos`.

The second compile error is due to the `in vec2 TexCoords[]` and `out vec2 TexCoords` have the same name. I renamed `out TexCoords` to `out gTexCoords[]`.

---

After fixing the issues listed above, new errors occur:

![[Pasted image 20231215234959.png]]

I change the statements to assignments:

```c++
vec3 faceNormal = normalize(cross(FragPos[1] - FragPos[0], FragPos[2] - FragPos[0]));
vec3 facePos = (FragPos[0] + FragPos[1] + FragPos[2]) / 3.0;
```

---

After fixing the above issues, the compiler complains about the output array does not have fixed size:

![[Pasted image 20231215235523.png]]

Therefore the output array is modified to:

```c++
out vec2 gTexCoords[3];
```

---

Then it appears that the geometry shader can only output 1 `gTexCoords`, therefore the declaration of it is modified to:

```c++
out vec2 gTexCoords;
```

And its value is determined by the average:

```c++
gTexCoords = (TexCoords[0] + TexCoords[1] + TexCoords[2]) / 3.0;
```

## 7.4. The dissolve effect is not what is expected

![[Pasted image 20231216000513.png]]

As the graph showing, the dissolve effect has two problems:

1. The dissolved part is colored black. I forgot to adjust the alpha component of the pixel, but the alpha component doesn't work even if I modify it.
2. The direction of dissolve of left half deer and right half deer is different. In the graph, the left half deer dissolves from front, and the right half deer dissolves from the back.

To solve the first problem, I use `discard` to discard the pixel instead of modifying the alpha component.

To solve the second problem, I use the object space coordinates. The value used to compare with `dissolveFactor` is named `normalizedXPos`. It is calculated by the formula below:

$$
\text{normalizedXPos} = \frac{\text{ObjectSpacePos.x} - (-25.6985)}{22.7548 - (-25.6985)}
$$

- $-25.6985$: The lower bound of x position in the object file.
- $22.7548$: The upper bound of x position in the object file.

The modified fragment shader is shown below:

```c++
#version 330 core

// Advanced:
// Implement Dissolve effect

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;
in vec3 ObjectSpacePos;

out vec4 FragColor;

uniform sampler2D textureSampler;
uniform float dissolveFactor;

void main()
{
    vec4 texColor = texture(textureSampler, TexCoords);
    float xPosLowerBound = -25.6985;
    float xPosUpperBound = 22.7548;
    float normalizedXPos = (ObjectSpacePos.x - xPosLowerBound) / (xPosUpperBound - xPosLowerBound);
    if(normalizedXPos < dissolveFactor)
        discard;
    FragColor = texColor;
}
```