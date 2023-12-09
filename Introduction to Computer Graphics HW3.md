# 1. TODO Parts in main

## 1.1. Create shaders and programs for each approach

As in HW2, there are functions `createShader` and `createProgram` to create the programs for each approach. The only difference is that the functions can handle geometry shaders too. The functions `createShader` and `createProgram` have following definitions:

```c++
// Create a shader based on given filename and type.
// filename: A c string specifying the shader file "shader.vert", "shader.frag", or "shader.geom"
// type: The type of the shader. Can be "vert", "frag", or "geom" for vertex shader, fragment shader or geometry shader.
unsigned int createShader(const char* filename, const char* type);

// Create a program based on given shaders.
unsigned int createProgram(unsigned int vertexShader, unsigned int geometryShader, unsigned int fragmentShader);
```

Using the two functions above, we can create the program for each approach. I want to call `glUseProgram` in the `while` loop, therefore this part is not implemented here.

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

# 2. Problems

## 2.1. Object.h not detected

In the source file `main.cpp`, the include:

```c++
#include "Object.h"
```

Is not recognized. I find out that the file is `object.h` in the `include` folder, and the correct include is:

```c++
#include "object.h"
```