Tag: #computer-graphics 
Previous: [[Create Shader in OpenGL]]
Link: 

[TOC]

---

The function must contain 3 function calling: (<u>1, 2</u>)

- `GLuint glCreateShader(GLenum shaderType)`
	- Specifies the type of shader.
	- Possible values in enumerator:
		- `GL_COMPUTE_SHADER`
		- `GL_VERTEX_SHADER`: [[Vertex Shader]]
		- `GL_TESS_CONTROL_SHADER`
		- `GL_TESS_EVALUATION_SHADER`
		- `GL_GEOMETRY_SHADER`: [[Geometry Shader]]
		- `GL_FRAGMENT_SHADER`: [[Fragment Shader]]
- `void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length)`
	- Import the shader code.
	- `shader`: The object created by `glCreateShader`.
	- `count`: The number of elements in the `string` and `length` arrays.
	- `string`: An array of pointers to strings of source code.
	- `length`: An array of string lengths.
- `void glCompileShader(GLuint shader)`
	- Compile the shader.
	- `shader`: The object created by `glCreateShader`.

The implementation will look like this: (<u>3</u>)

```c++
unsigned int createShader(const string& filename, const string& type)
{
	// create shader
	GLuint shader;
	if(type == "vert")
		shader = glCreateShader(GL_VERTEX_SHADER);
	else if(type == "frag")
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	else
		cerr << "In function createShader: shader type is not defined.\n";

	// shader source
	string file = readFile(filename);
	const char* c_str_file = file.c_str();
	glShaderSource(shader, 1, &c_str_file, nullptr);

	// compile shader
	glCompileShader(shader);

	// return shader
	return shader;
}
```

---

# Reference

1. Introduction to Computer Graphics TAs. “OpenGL Shader & GLSL, HW2 Tutorial.” NYCU EC114[GF], November 13, 2023.
2. “glShaderSource - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glShaderSource.xhtml.
3. “openGL API glShaderSource详解_妙为的博客-CSDN博客.” Accessed November 15, 2023. https://blog.csdn.net/aoxuestudy/article/details/121945058.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.