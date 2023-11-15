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

Following the TODO instruction, the loading texture part is done using a function `loadTexture`. Therefore the implementation of TODO#2 in the main function is:

```c++
/* TODO#2: Load texture
 * Hint:
 *       loadTexture
 * Note:
 *       penguin texture filename: "obj/penguin_diffuse.jpg"
 *       board texture filename : "obj/surfboard_diffuse.jpg"
 */
unsigned int penguinTexture = loadTexture("obj/penguin_diffuse.jpg");
unsigned int surfboardTexture = loadTexture("obj/surfboard_diffuse.jpg");
```

To complete the function `loadTexture`, following opengl functions should be used: (<u>1, 4, 5</u>)

- `void glEnable(Glenum cap)`
	- This function enables the texture.
	- `cap`: Pass `GL_TEXTURE_2D` to enable textures.
- `void glGenTextures(GLsizei n, GLuint* textures)`
	- Specify the number of textures and store it in an unsigned integer array.
	- `n`: Number of textures.
	- `textures`: The array for storing textures.
- `void glBindTexture(GLenum target, GLuint texture)`
	- Bind a texture to a target.
	- `target`: An enumerator, may pass value `GL_TEXTURE_1D`, `GL_TEXTURE_2D`, `GL_TEXTURE_3D`, or `GL_TEXTURE_1D_ARRAY`.
	- `texture`: A texture object.
- `void glTexParameteri(GLenum target, GLenum pname, GLint param)`
	- This function sets the parameters used in textures.
	- `target`: An enumerator, may pass value `GL_TEXTURE_1D`, `GL_TEXTURE_2D`, `GL_TEXTURE_3D`, or `GL_TEXTURE_1D_ARRAY`.
	- `pname`: Specify a parameter. Following parameter can be used:
		- `GL_TEXTURE_WRAP_S`: Specifies the wrapping mode for texture in the `S` direction. Some useful parameters are listed below:
			- `GL_REPEAT`: Repeat the texture images if texture coordinates exceed 1.
		- `GL_TEXTURE_WRAP_T`: Specifies the wrapping mode for texture in the `T` direction. Some useful parameters are listed below:
			- `GL_REPEAT`: Repeat the texture images if texture coordinates exceed 1.
		- `GL_TEXTURE_MIN_FILTER`: Because the texture coordinates have floating point value, we specify which texture pixel to map the texture coordinate to. The method of mapping is applied when the texture is scaled down (minified). Useful parameters are listed:
			- `GL_NEAREST`: Pick the value that is nearest (in Manhattan distance).
			- `GL_LINEAR`: Use the weighted average of the four texture elements that are closest to the current coordinate.
		- `GL_TEXTURE_MAG_FILTER`: Because the texture coordinates have floating point value, we specify which texture pixel to map the texture coordinate to. The method of mapping is applied when the texture is scaled up (magnified). Useful parameters are listed:
			- `GL_NEAREST`: Pick the value that is nearest (in Manhattan distance).
			- `GL_LINEAR`: Use the weighted average of the four texture elements that are closest to the current coordinate.
	- `param`: The parameter set. The available options are listed above.
- `void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data)`
	- Generate a two-dimensional texture image.
	- `target`: An enumerator, may pass value `GL_TEXTURE_1D`, `GL_TEXTURE_2D`, `GL_TEXTURE_3D`, or `GL_TEXTURE_1D_ARRAY`.
	- `level`: Specifies the level-of-detail number. `0` is the base image level.
	- `internalformat`: Specifies what color components will be in the texture. `GL_RGB` is a useful value.
	- `width`: Specifies the width of the texture image.
	- `height`: Specifies the height of the texture image.
	- `border`: Must be `0`.
	- `format`: Specifies the format of `data`. `GL_RGB` is a useful value.
	- `type`: Specifies the data type of the `data`. For RGB images, `GL_UNSIGNED_BYTE` is used.
	- `data`: A pointer to the image data.



# 2. Reference

1. Introduction to Computer Graphics TAs. “OpenGL Shader & GLSL, HW2 Tutorial.” NYCU EC114[GF], November 13, 2023.
2. “glShaderSource - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glShaderSource.xhtml.
3. “openGL API glShaderSource详解_妙为的博客-CSDN博客.” Accessed November 15, 2023. https://blog.csdn.net/aoxuestudy/article/details/121945058.
4. “glTexParameter - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml.
5. “glTexImage2D - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml.