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

Also, `stb_image.h` is used to input the specified `jpg` file. Function `stbi_load` can read the `jpg` file and get its width, height and channels. (<u>6</u>)

```c++
STBIDEF stbi_uc *stbi_load(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
```

- `STBIDEF`: The function type, may be defined `static` or `extern`.
- `stbi_uc`: Unsigned char.
- `filename`: Filename represented by a c string.
- `x`: An integer pointer to save the width of the picture.
- `y`: An integer pointer to save the height of the picture.
- `channels_in_file`: An integer pointer to save the number of channels.
- `desired_channels`: To force that many components per pixel. `0` for not forcing.

Using the functions above, the function `loadTexture` is implemented as follow:

```c++
/* TODO#2: Load texture
 * Hint:
 *       glEnable, glGenTextures, glBindTexture, glTexParameteri, glTexImage2D
 */
unsigned int loadTexture(const char* tFileName) 
{
	// set texture object
	glEnable(GL_TEXTURE_2D);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	// read from file
	int imgHeight, imgWidth, imgChannels;
	unsigned char* imgFile = stbi_load(tFileName, &imgWidth, &imgHeight, &imgChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile);
	return texture;
}
```

## 1.4. TODO#3: Set up VAO, VBO

This TODO part uses a function `modelVAO`, which uses a parameter with type `Object`.

The `Object` that needs to be passed to the functions is declared globally in `Main.cpp`:

```c++
Object penguinModel("obj/penguin.obj");
Object boardModel("obj/surfboard.obj");
```

And the TODO part in the `main` function will be:

```c++
/* TODO#3: Set up VAO, VBO
 * Hint:
 *       modelVAO
 */
unsigned int penguinVAO, boardVAO;
penguinVAO = modelVAO(penguinModel);
boardVAO = modelVAO(boardModel);
```

To set up the VAO and VBO, following functions are used: (<u>1, 7</u>)

- `void glGenVertexArrays(GLsizei n, GLuint* arrays)`
	- `n`: The number of vertex array object names to be generated.
	- `arrays`: An array where the generated vertex array is stored.
- `void glBindVertexArray(GLuint array)`
	- `array`: The name of the vertex array to bind.
- `void glGenBuffers(GLsizei n, GLuint* buffers)`
	- `n`: The number of buffer objects to be generated.
	- `buffers`: An array where the generated buffer are stored.
- `void glBindBuffer(GLenum target, GLuint buffer)`
	- `target`: The target of the buffer to bind on. `GL_ARRAY_BUFFER` or `GL_TEXTURE_BUFFER`.
	- `buffer`: The name of a buffer object.
- `void glBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)`
	- `target`: The target of the buffer to bind on. `GL_ARRAY_BUFFER` or `GL_TEXTURE_BUFFER`.
	- `size`: The size in bytes of the buffer object's new data store.
	- `data`: A pointer to the data that will be copied.
	- `usage`: The expected usage pattern of the data. `GL_STATIC_DRAW` is for the case that data will be stored once and used at most a few times.
- `void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)`
	- `index`: The index of the vertex attribute to be modified.
	- `size`: The number of components per vertex attribute.
	- `type`: The data type of elements in the array. `GL_FLOAT` is for float.
	- `stride`: The byte offset between vertex attributes.
	- `pointer`: An offset of the first component. The initial value is `0`.
- `void glEnableVertexAttribArray(GLuint index)`
	- `index`: The index of the attribute to be enabled or disabled.

Using the functions above, the `modelVAO` function will be:

```c++
/* TODO#3: Set up VAO, VBO
 * Hint:
 *       glGenVertexArrays, glBindVertexArray, glGenBuffers, glBindBuffer, glBufferData,
 *       glVertexAttribPointer, glEnableVertexAttribArray, 
 */
unsigned int modelVAO(Object& model)
{
	unsigned int VAO, VBO_positions, VBO_normals, VBO_texcoords;

	// generate and bind VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// generate VBO for positions
	glGenBuffers(1, &VBO_positions);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_positions);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(float), model.positions.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// generate VBO for normals
	glGenBuffers(1, &VBO_normals);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_normals);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(float), model.normals.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	// generate VBO for texcoords
	glGenBuffers(1, &VBO_texcoords);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_texcoords);
	glBufferData(GL_ARRAY_BUFFER, model.texcoords.size() * sizeof(float), model.texcoords.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);

	// unbind VAO
	glBindVertexArray(0);

	return VAO;
}
```

## 1.5. TODO#4: Data connection

In this section, we need to connect the data between the application and the shader program. In order to do so, we have to get the locations of the uniform variable. We can use `glGetUniformLocation`: (<u>8</u>)

```c++
GLint glGetUniformLocation(GLuint program, const GLchar* name);
```

- `program`: The program object.
- `name`: A string of the name of the uniform variable.

The implementation of data connection:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
GLint projLoc = glGetUniformLocation(shaderProgram, "projection");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
```

## 1.6. TODO#5: Render board and penguin

### 1.6.1. TODO#5.1: Render board

```c++
/* TODO#5-1: Render Board
 *    1. Set up board model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the board.(for key 'g')
 * Hint:
 *	  rotate, translate, scale
 *    glUniformMatrix4fv, glUniform1i
 *    glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 boardModelMatrix = glm::mat4(1.0f);
boardModelMatrix = glm::scale(boardModelMatrix, glm::vec3(0.03, 0.03, 0.03));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
boardModelMatrix = glm::translate(boardModelMatrix, glm::vec3(0, -0.5, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(boardModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUseProgram(0);
```

To render the board, the matrix `boardModelMatrix` is set. Then, the uniform values and matrices are passed using `glUniformMatrix4fv`, `glUniform1f` and `glUniform1i`.

### 1.6.2. TODO#5.2 Render penguin

```c++
/* TODO#5-2: Render Penguin
 *    1. Set up penguin model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the penguin.(for key 'g')
 * Hint:
 *	 rotate, translate, scale
 *   glUniformMatrix4fv, glUniform1i
 *   glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 penguinModelMatrix = glm::mat4(1.0f);
penguinModelMatrix = glm::scale(penguinModelMatrix, glm::vec3(0.025, 0.025, 0.025));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(-90.0f), glm::vec3(1, 0, 0));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
penguinModelMatrix = glm::translate(penguinModelMatrix, glm::vec3(0, 0, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(penguinModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUseProgram(0);
```

Similar to the section [[#1.6.1. TODO 5.1 Render board]], the implementation uses matrix `penguinModelMatrix` to store the transformation, and functions `glUniformMatrix4fv`, `glUniform1f` and `glUniform1i` for passing uniform variables.

## 1.7. TODO#6 Update swingAngle, swingPos, squeezeFactor

```c++
/* TODO#6: Update "swingAngle", "swingPos", "squeezeFactor"
 * Speed:
 *	  swingAngle   : 20 degrees/sec
 *    swingPos     : 1.0f / sec
 *    squeezeFactor: 90 degrees/sec
 */
swingAngle += swingAngleDir * 20 * dt;
while (swingAngle > 20 || swingAngle < -20)
{
	if (swingAngle > 20)
	{
		swingAngle = 40 - swingAngle;
		swingAngleDir = -1;
	}
	if (swingAngle < -20)
	{
		swingAngle = -40 - swingAngle;
		swingAngleDir = 1;
	}
}
swingPos += swingPosDir * 1.0f * dt;
while (swingPos > 2 || swingPos < 0)
{
	if (swingPos > 2)
	{
		swingPos = 4 - swingPos;
		swingPosDir = -1;
	}
	if (swingPos < 0)
	{
		swingPos = -swingPos;
		swingPosDir = 1;
	}
}
if (squeezing)
{
	squeezeFactor += 90.0f * dt;
}
```

The `swingPos` and `swingAngle` is modified according to the requirement. And `sqeezeFactor` is modified if is squeezing.

To make sure that `swingPos` and `swingAngle` do not exceed their boundaries, I use a `while` loop to correct them.

## 1.8. TODO#7 Key callback

```c++
/* TODO#7: Key callback
 *    1. Press 's' to squeeze the penguin.
 *    2. Press 'g' to change to grayscale.
 *    3. Print "KEY S PRESSED" when key 's' is pressed, and similarly for other keys.
 */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		squeezeFactor = squeezeFactor == 1 ? 0 : 1;
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
		useGrayscale = useGrayscale ? 0 : 1;
}
```

This section is a simple `if` statement. I toggle the parameters `squeezeFactor` and `useGrayscale` if the corresponding key is pressed.

## 1.9. Vertex shader TODO

```c++
// TODO: Implement squeeze effect and update normal transformation
//   1. Adjust the vertex position to create a squeeze effect based on squeezeFactor.
//   2. Update worldPos using the model matrix (M).
//   3. Calculate the final gl_Position using the perspective (P), view (V), and updated worldPos.
//   4. Update the normal transformation for lighting calculations.
// Note: Ensure to handle the squeeze effect for both y and z coordinates.
vec3 squeezedPos = vec3(aPos.x, aPos.z * sin(squeezeFactor) / 2, aPos.y * sin(squeezeFactor) / 2);
worldPos = M * vec4(squeezedPos, 1.0);
gl_Position = P * V * worldPos;
normal = mat3(transpose(inverse(M))) * aNormal;
```

1. According to the requirement (<u>1</u>), for vertex (`x`, `y`, `z`): $$
\begin{array}{}
	y & \text{+=} & z \cdot \sin(\text{squeezeFactor})/2 \\
	z & \text{+=} & y\cdot \sin(\text{squeezeFactor})/2
\end{array}
$$So, the coordinate `squeezedPos` is calculated based on this formula.
2. The `worldPos` is updated using the matrix `M`.
3. The final `gl_Position` is calculated using the perspective matrix `P` and the view matrix `V`.
4. Using the inverse transpose of the model matrix `M`, it corrects for the distortion caused by non-uniform scaling.

## 1.10. Fragment shader TODO

```c++
// TODO: Implement Grayscale Effect
//   1. Retrieve the color from the texture at texCoord.
//   2. If useGrayscale is true,
//        a. Calculate the grayscale value using the dot product with the luminance weights(0.299, 0.587, 0.114).
//        b. Set FragColor to a grayscale version of the color.
//   Note: Ensure FragColor is appropriately set for both grayscale and color cases.
vec4 color = texture(ourTexture, texCoord);
if (useGrayscale)
{
	float gray = dot(color.rgb, vec3(0.299, 0.587, 0.114));
	FragColor = vec4(gray, gray, gray, 1.0);
}
else
{
	FragColor = color;
}
```

1. To retrieve the texture, function `texture` is used.
2. An `if` statement is used to determine whether the `useGrayscale` is `1`.
	1. Function `dot` is used to calculate the dot products.
	2. The fragment color is set to gray scale in the first case, and the original color in the second case.

# 2. Problems met

## 2.1. Problem 1: Black screen

Upon launching the code, a black screen appears:

![[Pasted image 20231122001011.png]]

### 2.1.1. Solution 1: Check shader compilation and linking

To check the shader compilation errors, I added these lines after the compilation of any shader, in function `createShader`:

```c++
// check for shader compile errors
GLint success;
glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
if (!success)
{
	GLchar infoLog[512];
	glGetShaderInfoLog(shader, 512, NULL, infoLog);
	cerr << "Shader compilation failed.\n" << infoLog << endl;
	exit(1);
}
```

And these lines in function `createProgram` for checking the linking errors:

```c++
// check for program link errors
GLint success;
glGetProgramiv(program, GL_LINK_STATUS, &success);
if (!success)
{
	GLchar infoLog[512];
	glGetProgramInfoLog(program, 512, NULL, infoLog);
	cerr << "Program linking failed.\n" << infoLog << endl;
	exit(1);
}
```

Nothing has been output, so the compilation and linking is working. Therefore, I keep looking.

### 2.1.2. Solution 2: Check that glBindVertexArray is called before drawing each object

My original code in [[#1.6.1. TODO 5.1 Render board]] and [[#1.6.2. TODO 5.2 Render penguin]] is:

```c++
/* TODO#5-1: Render Board
 *    1. Set up board model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the board.(for key 'g')
 * Hint:
 *	  rotate, translate, scale
 *    glUniformMatrix4fv, glUniform1i
 *    glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 boardModelMatrix = glm::mat4(1.0f);
boardModelMatrix = glm::scale(boardModelMatrix, glm::vec3(0.03, 0.03, 0.03));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
boardModelMatrix = glm::translate(boardModelMatrix, glm::vec3(0, -0.5, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(boardModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUseProgram(0);

/* TODO#5-2: Render Penguin
 *    1. Set up penguin model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the penguin.(for key 'g')
 * Hint:
 *	 rotate, translate, scale
 *   glUniformMatrix4fv, glUniform1i
 *   glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 penguinModelMatrix = glm::mat4(1.0f);
penguinModelMatrix = glm::scale(penguinModelMatrix, glm::vec3(0.025, 0.025, 0.025));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(-90.0f), glm::vec3(1, 0, 0));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
penguinModelMatrix = glm::translate(penguinModelMatrix, glm::vec3(0, 0, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(penguinModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUseProgram(0);
```

It turns out that I forgot to implement `glActiveTexture`, `glBindTexture`,`glBindVertexArray` and `glDrawArrays`. Here is the correct implementation:

```c++
/* TODO#5-1: Render Board
 *    1. Set up board model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the board.(for key 'g')
 * Hint:
 *	  rotate, translate, scale
 *    glUniformMatrix4fv, glUniform1i
 *    glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 boardModelMatrix = glm::mat4(1.0f);
boardModelMatrix = glm::scale(boardModelMatrix, glm::vec3(0.03, 0.03, 0.03));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
boardModelMatrix = glm::translate(boardModelMatrix, glm::vec3(0, -0.5, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(boardModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, surfboardTexture);
glBindVertexArray(boardVAO);
glDrawArrays(GL_TRIANGLES, 0, boardModel.positions.size());
glUseProgram(0);

/* TODO#5-2: Render Penguin
 *    1. Set up penguin model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the penguin.(for key 'g')
 * Hint:
 *	 rotate, translate, scale
 *   glUniformMatrix4fv, glUniform1i
 *   glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 penguinModelMatrix = glm::mat4(1.0f);
penguinModelMatrix = glm::scale(penguinModelMatrix, glm::vec3(0.025, 0.025, 0.025));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(-90.0f), glm::vec3(1, 0, 0));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
penguinModelMatrix = glm::translate(penguinModelMatrix, glm::vec3(0, 0, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(penguinModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, penguinTexture);
glBindVertexArray(penguinVAO);
glDrawArrays(GL_TRIANGLES, 0, penguinModel.positions.size());
glUseProgram(0);
```

However, this does not solve the black screen problem. So I have to keep looking for bugs.

### 2.1.3. Solution 3: Check uniform variables

In [[#1.5. TODO 4 Data connection]], I wrote the code:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
GLint projLoc = glGetUniformLocation(shaderProgram, "projection");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
```

It binds the location of uniform variable `"model"`, `"view"`, and `"projection"`, but the vertex shader code uses `"M"`, `"V"`, and `"P"` for its variable names. Therefore I modify the variable names:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "M");
GLint viewLoc = glGetUniformLocation(shaderProgram, "V");
GLint projLoc = glGetUniformLocation(shaderProgram, "P");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
```

After this modification, the penguin appears, but not the surf board. Also, the penguin has no shader effects.

## 2.2. Problem 2: The penguin appears with no texture, and the surfboard missing

Now the shape of the penguin appears, but with no texture and shader. Also, the surfboard is missing.

![[Pasted image 20231122010222.png]]

### 2.2.1. Solution 1: Shader uniforms

I figured that I didn't pass the `ourTexture` uniform variable to the program. The following code block shows the corresponding section that I forgot to add it:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "M");
GLint viewLoc = glGetUniformLocation(shaderProgram, "V");
GLint projLoc = glGetUniformLocation(shaderProgram, "P");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
```

```c++
/* TODO#5-1: Render Board
 *    1. Set up board model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the board.(for key 'g')
 * Hint:
 *	  rotate, translate, scale
 *    glUniformMatrix4fv, glUniform1i
 *    glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 boardModelMatrix = glm::mat4(1.0f);
boardModelMatrix = glm::scale(boardModelMatrix, glm::vec3(0.03, 0.03, 0.03));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
boardModelMatrix = glm::translate(boardModelMatrix, glm::vec3(0, -0.5, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(boardModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, surfboardTexture);
glBindVertexArray(boardVAO);
glDrawArrays(GL_TRIANGLES, 0, boardModel.positions.size());
glUseProgram(0);

/* TODO#5-2: Render Penguin
 *    1. Set up penguin model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the penguin.(for key 'g')
 * Hint:
 *	 rotate, translate, scale
 *   glUniformMatrix4fv, glUniform1i
 *   glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 penguinModelMatrix = glm::mat4(1.0f);
penguinModelMatrix = glm::scale(penguinModelMatrix, glm::vec3(0.025, 0.025, 0.025));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(-90.0f), glm::vec3(1, 0, 0));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
penguinModelMatrix = glm::translate(penguinModelMatrix, glm::vec3(0, 0, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(penguinModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, penguinTexture);
glBindVertexArray(penguinVAO);
glDrawArrays(GL_TRIANGLES, 0, penguinModel.positions.size());
glUseProgram(0);
```

I added it, and the code becomes:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "M");
GLint viewLoc = glGetUniformLocation(shaderProgram, "V");
GLint projLoc = glGetUniformLocation(shaderProgram, "P");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
GLint ourTextureLoc = glGetUniformLocation(shaderProgram, "ourTexture");
```

```c++
/* TODO#5-1: Render Board
 *    1. Set up board model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the board.(for key 'g')
 * Hint:
 *	  rotate, translate, scale
 *    glUniformMatrix4fv, glUniform1i
 *    glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 boardModelMatrix = glm::mat4(1.0f);
boardModelMatrix = glm::scale(boardModelMatrix, glm::vec3(0.03, 0.03, 0.03));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
boardModelMatrix = glm::rotate(boardModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
boardModelMatrix = glm::translate(boardModelMatrix, glm::vec3(0, -0.5, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(boardModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUniform1i(ourTextureLoc, 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, surfboardTexture);
glBindVertexArray(boardVAO);
glDrawArrays(GL_TRIANGLES, 0, boardModel.positions.size());
glUseProgram(0);

/* TODO#5-2: Render Penguin
 *    1. Set up penguin model matrix.
 *    2. Send model, view, and projection matrices to the program.
 *    3. Send squeezeFactor, useGrayscale, or other parameters to the program.(for key 's')
 *    4. Set the value of the uniform variable "useGrayscale" and render the penguin.(for key 'g')
 * Hint:
 *	 rotate, translate, scale
 *   glUniformMatrix4fv, glUniform1i
 *   glUniform1i, glActiveTexture, glBindTexture, glBindVertexArray, glDrawArrays
 */
glm::mat4 penguinModelMatrix = glm::mat4(1.0f);
penguinModelMatrix = glm::scale(penguinModelMatrix, glm::vec3(0.025, 0.025, 0.025));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(-90.0f), glm::vec3(1, 0, 0));
penguinModelMatrix = glm::rotate(penguinModelMatrix, glm::radians(swingAngle), glm::vec3(0, 1, 0));
penguinModelMatrix = glm::translate(penguinModelMatrix, glm::vec3(0, 0, swingPos));
glUseProgram(shaderProgram);
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(penguinModelMatrix));
glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(perspective));
glUniform1f(squeezeFactorLoc, squeezeFactor);
glUniform1i(useGrayscaleLoc, useGrayscale ? 1 : 0);
glUniform1i(ourTextureLoc, 0);
glActiveTexture(GL_TEXTURE0);
glBindTexture(GL_TEXTURE_2D, penguinTexture);
glBindVertexArray(penguinVAO);
glDrawArrays(GL_TRIANGLES, 0, penguinModel.positions.size());
glUseProgram(0);
```

However, the problem is not solved.

### 2.2.2. Solution 2: Check texture load

Maybe the texture is not load properly in function `loadTexture`, therefore I added an `if` statement to check whether the image loaded correctly.

```c++
/* TODO#2: Load texture
 * Hint:
 *       glEnable, glGenTextures, glBindTexture, glTexParameteri, glTexImage2D
 */
unsigned int loadTexture(const char* tFileName)
{
	// set texture object
	glEnable(GL_TEXTURE_2D);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// read from file
	int imgHeight, imgWidth, imgChannels;
	unsigned char* imgFile = stbi_load(tFileName, &imgWidth, &imgHeight, &imgChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile);

    // check if the image is loaded
    if (imgFile == NULL)
    {
        cerr << "Failed to load texture: " << tFileName << endl;
        exit(1);
    }

	return texture;
}
```

It seems that the texture is loaded correctly.

### 2.2.3. Solution 3: Enable OpenGL debug output

To find out potential error, I write a `while` loop at the end of the rendering loop:

```c++
GLenum err;
while ((err = glGetError()) != GL_NO_ERROR)
{
	cerr << "OpenGL error: " << err << endl;
}
```

And it outputs:

```
OpenGL error: 1280
```

Which means `GL_INVALID_ENUM` (<u>9</u>). After placing the printing debug message every where, I find out that the following line in function `loadTexture` is for legacy:

```c++
// set texture object
glEnable(GL_TEXTURE_2D);
```

Therefore I modified the function `loadTexture` to:

```c++
/* TODO#2: Load texture
 * Hint:
 *       glEnable, glGenTextures, glBindTexture, glTexParameteri, glTexImage2D
 */
unsigned int loadTexture(const char* tFileName)
{
	// set texture object
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// read from file
	int imgHeight, imgWidth, imgChannels;
	unsigned char* imgFile = stbi_load(tFileName, &imgWidth, &imgHeight, &imgChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile);

    // check if the image is loaded
    if (imgFile == NULL)
    {
        cerr << "Failed to load texture: " << tFileName << endl;
        exit(1);
    }

    // free the image
    stbi_image_free(imgFile);

    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}
```

As a result, no error appears again. But the problem is not solved.

### 2.2.4. Solution 4: Add support for RGBA textures

Maybe the texture image is `GL_RGBA` and has 4 channels, therefore I used an `if` statement to support the 4-channel format:

```c++
/* TODO#2: Load texture
 * Hint:
 *       glEnable, glGenTextures, glBindTexture, glTexParameteri, glTexImage2D
 */
unsigned int loadTexture(const char* tFileName)
{
	// set texture object
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// read from file
	int imgHeight, imgWidth, imgChannels;
	unsigned char* imgFile = stbi_load(tFileName, &imgWidth, &imgHeight, &imgChannels, 0);
    if(imgChannels == 3)
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgFile);
    else if(imgChannels == 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgFile);
    else
    {
        cerr << "The texture file " << tFileName << "has invalid channel numbers." << endl;
        exit(1);
    }

    // check if the image is loaded
    if (imgFile == NULL)
    {
        cerr << "Failed to load texture: " << tFileName << endl;
        exit(1);
    }

    // free the image
    stbi_image_free(imgFile);

    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}
```

Although the problem is not solved, adding support for 4-channel images may be useful in future.

### 2.2.5. Solution 5: Check uniform location

It is possible that the uniform variables are not active in the shader program, and the uniform locations are not found (<u>10</u>). Therefore, I added `if` statements to check these:

```c++
/* TODO#4: Data connection - Retrieve uniform variable locations
 *    1. Retrieve locations for model, view, and projection matrices.
 *    2. Obtain locations for squeezeFactor, grayscale, and other parameters.
 * Hint:
 *    glGetUniformLocation
 */
GLint modelLoc = glGetUniformLocation(shaderProgram, "M");
GLint viewLoc = glGetUniformLocation(shaderProgram, "V");
GLint projLoc = glGetUniformLocation(shaderProgram, "P");
GLint squeezeFactorLoc = glGetUniformLocation(shaderProgram, "squeezeFactor");
GLint useGrayscaleLoc = glGetUniformLocation(shaderProgram, "useGrayscale");
GLint ourTextureLoc = glGetUniformLocation(shaderProgram, "ourTexture");
if (modelLoc == -1)
{
	cerr << "In function main: modelLoc is not found." << endl;
	exit(1);
}
if (viewLoc == -1)
{
	cerr << "In function main: viewLoc is not found." << endl;
	exit(1);
}
if (projLoc == -1)
{
	cerr << "In function main: projLoc is not found." << endl;
	exit(1);
}
if (squeezeFactorLoc == -1)
{
	cerr << "In function main: squeezeFactorLoc is not found." << endl;
	exit(1);
}
if (useGrayscaleLoc == -1)
{
	cerr << "In function main: useGrayscaleLoc is not found." << endl;
	exit(1);
}
if (ourTextureLoc == -1)
{
	cerr << "In function main: ourTextureLoc is not found." << endl;
	exit(1);
}
```

It turns out that the uniform names are defined, and the problem still exists.

### 2.2.6. Solution 6: Check vertex shader passing texture coordinates

By temporarily modify the fragment shader:

```c++
FragColor = vec4(texCoord, 0.0, 1.0);
```

This should have a gradient effect on the render result. But instead of gradient, a black screen is shown. Therefore, I concluded that the texture coordinate is not passed correctly from vertex shader. The corrected vertex shader code is shown below:

```c++
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

uniform float squeezeFactor;
uniform float offest;

out vec2 texCoord;
out vec3 normal;

vec4 worldPos;

void main()
{
	// TODO: Implement squeeze effect and update normal transformation
	//   1. Adjust the vertex position to create a squeeze effect based on squeezeFactor.
	//   2. Update worldPos using the model matrix (M).
	//   3. Calculate the final gl_Position using the perspective (P), view (V), and updated worldPos.
	//   4. Update the normal transformation for lighting calculations.
	// Note: Ensure to handle the squeeze effect for both y and z coordinates.
	vec3 squeezedPos = vec3(aPos.x, aPos.y + aPos.z * sin(squeezeFactor) / 2, aPos.z + aPos.y * sin(squeezeFactor) / 2);
	worldPos = M * vec4(squeezedPos, 1.0);
    gl_Position = P * V * worldPos;
    normal = mat3(transpose(inverse(M))) * aNormal;

    texCoord = aTexCoord;
}
```

After the passing of the texture coordinates, the texture successfully maps on the objects.

![[Screenshot from 2023-11-22 03-18-01.png]]

# 3. Reference

1. Introduction to Computer Graphics TAs. “OpenGL Shader & GLSL, HW2 Tutorial.” NYCU EC114[GF], November 13, 2023.
2. “glShaderSource - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glShaderSource.xhtml.
3. “openGL API glShaderSource详解_妙为的博客-CSDN博客.” Accessed November 15, 2023. https://blog.csdn.net/aoxuestudy/article/details/121945058.
4. “glTexParameter - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml.
5. “glTexImage2D - OpenGL 4 Reference Pages.” Accessed November 15, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml.
6. GitHub. “Stb/Stb_image.h at Master · Nothings/Stb.” Accessed November 20, 2023. https://github.com/nothings/stb/blob/master/stb_image.h.
7. “glEnableVertexAttribArray - OpenGL 4 Reference Pages.” Accessed November 20, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glEnableVertexAttribArray.xhtml.
8. “glGetUniformLocation - OpenGL 4 Reference Pages.” Accessed November 21, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml.
9. “OpenGL Error - OpenGL Wiki.” Accessed November 22, 2023. https://www.khronos.org/opengl/wiki/OpenGL_Error.
10. “glGetUniformLocation - OpenGL 4 Reference Pages.” Accessed November 22, 2023. https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml.