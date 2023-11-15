- 學號：109611066
- 姓名：吳典謀

# 1. TODOs and their implementations

## 1.1. TODO#0: Change window title

I changed the title according to the TODO instruction.

```c++
/* TODO#0: Change window title to "HW2 - your student id"
*        Ex. HW2 - 312550000
*/
GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "HW2 - 109611066", NULL, NULL);
```

## 1.2. TODO#1: Create vertex shader, fragment shader, shader program

To simplify the method of creating shader, the setting and creating part is written in functions. Calling them in main function looks like this: (<u>1</u>)

```c++
/* TODO#1: Create vertex shader, fragment shader, shader program
 * Hint:
 *       createShader, createProgram, glUseProgram
 * Note:
 *       vertex shader filename: "vertexShader.vert"
 *		 fragment shader filename: "fragmentShader.frag"
 */
unsigned int vertexShader, fragmentShader, shaderProgram;
vertexShader = createShader("vertexShader.vert", "vert");
fragmentShader = createShader("fragmentShader.frag", "frag");
shaderProgram = createProgram(vertexShader, fragmentShader);
glUseProgram(shaderProgram);
```

### 1.2.1. TODO#1-1: createShader

This function must call 3 opengl functions. The functions are listed below: (<u>1, 2</u>)

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

The implementation contains determining the file type and reading from the file. The code is shown below: (<u>3</u>)

```c++
/* TODO#1-1: createShader
* Hint:
*       glCreateShader, glShaderSource, glCompileShader
*/
unsigned int createShader(const string& filename, const string& type)
{
	// create shader
	GLuint shader;
	if (type == "vert")
		shader = glCreateShader(GL_VERTEX_SHADER);
	else if (type == "frag")
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

### 1.2.2. TODO#1-2: createProgram

After that the shaders have been created, we should create programs and attach the shaders to them. This method will contain 4 opengl functions: (<u>1</u>)

- `GLuint glCreateProgram(void)`
	- Creates a program object.
- `void glAttachShader(GLuint program, GLuint shader)`
	- Attach the shader to the specified program.
	- `program`: A program object created by `glCreateProgram`.
	- `shader`: A shader created in [[#1.2.1. TODO 1-1 createShader]].
- `void glLinkProgram(GLuint program)`
	- Link the program specified so it can be executed later.
	- `program`: A program object created by `glCreateProgram`.
- `void glDetachShader(GLuint program, GLuint shader)`
	- Detaches the shader from the program.
	- `program`: A program object created by `glCreateProgram`.
	- `shader`: A shader created in [[#1.2.1. TODO 1-1 createShader]].

The implementation of the function `createProgram` is shown below: (<u>3</u>)

```c++
/* TODO#1-2: createProgram
* Hint:
*       glCreateProgram, glAttachShader, glLinkProgram, glDetachShader
*/
unsigned int createProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
	// create program
	GLuint program = glCreateProgram();

	// attach shaders to the programs
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// link programs
	glLinkProgram(program);

	// detach the shaders from the programs
	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	// return the program object
	return program
}
```

## 1.3. TODO#2: Load texture



# 2. Reference

1. Introduction to Computer Graphics TAs. “OpenGL Shader & GLSL, HW2 Tutorial.” NYCU EC114[GF], November 13, 2023.
2. “glShaderSource - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glShaderSource.xhtml.
3. “openGL API glShaderSource详解_妙为的博客-CSDN博客.” Accessed November 15, 2023. https://blog.csdn.net/aoxuestudy/article/details/121945058.