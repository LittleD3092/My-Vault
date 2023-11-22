Based on your description and the provided code, here are some potential reasons why the penguin might not be textured and the surfboard does not appear:

1. **Texture Loading and Binding**: After loading the texture with `stbi_load`, you correctly use `glTexImage2D` to create the texture, but ensure you're setting the correct format based on the number of image channels. For example, if `imgChannels` is 4, you should use `GL_RGBA` instead of `GL_RGB`. Also, make sure that `stbi_image_free(imgFile);` is called after `glTexImage2D`.

2. **Shader Uniform for Texture Sampler**: In the shader, make sure that the uniform sampler2D `ourTexture` is set to the correct texture unit index that you're using. Since you're activating texture unit 0 with `glActiveTexture(GL_TEXTURE0);`, the corresponding glUniform call `glUniform1i(ourTextureLoc, 0);` is correct. Make sure `ourTextureLoc` is not `-1`, which would indicate that the uniform location was not found.

3. **Texture Coordinates**: If the penguin's model does not have correct texture coordinates, it won't map the texture correctly. Ensure the texture coordinates are loaded and bound to the appropriate attribute in the VAO setup.

4. **VAO and VBO Binding**: Verify that the VAOs and VBOs are correctly set up for both models. Since the penguin appears but isn't textured, the issue might be with the texture coordinates or their attribute pointers.

5. **Draw Calls**: In your draw calls, you divide the size of the positions array by 3. Make sure that `boardModel.positions.size()` and `penguinModel.positions.size()` actually return the total count of the `float` elements. If these are indeed the counts of `float`s and not the count of vertices, the division by 3 would be unnecessary and could cause fewer triangles to be rendered, potentially resulting in missing objects.

6. **Face Culling**: If face culling is enabled and not mentioned in your code, it's possible that the surfboard is being culled. Make sure that face culling is either disabled with `glDisable(GL_CULL_FACE);` or set up correctly to cull the appropriate faces.

7. **Depth Testing**: If the surfboard is behind the penguin or outside the view frustum, it won't be visible. Since depth testing is enabled, ensure that the surfboard is within the near and far planes of your perspective projection and is not being occluded by the penguin.

8. **Error Checking**: The placement of `glGetError` after `glfwPollEvents()` is not ideal for catching errors immediately after they occur. It's better to place `glGetError` directly after OpenGL calls that you suspect might fail.

9. **Shader Compilation and Linking**: Ensure that there are no shader compilation or linking errors. You've provided code for error checking during shader creation, which is good practice.

10. **Graphics Context**: Since you're running this in a virtual machine (as seen from the window title bar), make sure that the VM is correctly set up to use GPU acceleration. Some virtual environments have poor support for 3D acceleration or require specific settings to enable it.

After addressing these points, if you're still facing issues, it would be helpful to check the console output for any error messages that might give further insight into what's going wrong.

---

Shading is not required for the basic rendering of textured objects. Even without shading, you should be able to see the texture applied to your models provided that the texture coordinates are correct and the texture is properly loaded and bound.

Shading involves calculating the effects of light sources on the objects' surfaces, which gives the scene more realism through the use of highlights and shadows. If you're not implementing lighting and shading, your objects will be rendered in their base colors or textures as they are in the texture image, which should be sufficient to see the texture on the penguin and the surfboard.

The issue you're facing with the penguin not showing a texture and the surfboard not appearing at all seems to be more related to the OpenGL state, texture handling, or the data being passed to OpenGL rather than shading.

Since you've checked the other points and are still facing issues, let's consider a few additional debugging steps:

1. **Shader Outputs**: Check that the vertex shader is passing the texture coordinates to the fragment shader correctly. You can temporarily modify the fragment shader to output the texture coordinates as colors to verify they are being received:
   ```glsl
   FragColor = vec4(texCoord, 0.0, 1.0);
   ```
   If the penguin turns out to be correctly colored in a gradient, then the texture coordinates are likely correct.

2. **Texture Sampler Binding**: Ensure that the texture sampler uniform in the fragment shader is set after you call `glUseProgram` and before the draw call for each object.

3. **Transparency and Alpha**: If the texture has an alpha channel and you're not handling it, this could result in seemingly missing textures. Make sure that you're uploading the texture with the correct format as indicated by `imgChannels`.

4. **Fragment Shader Logic**: Verify that the fragment shader logic is not discarding pixels or otherwise manipulating the texture colors in unexpected ways.

5. **OpenGL Context in VM**: You mentioned running this in a virtual machine. Make sure the VM supports the OpenGL version you're using and that the graphics drivers are properly installed. Sometimes VMs have issues with 3D acceleration which can cause unexpected rendering behavior.

6. **Graphics Debugging Tools**: Use tools like RenderDoc, gDEBugger, or even the debugging functionalities within your IDE to step through your rendering calls and examine the OpenGL state and the data in your textures and buffers.

7. **Minimal Test Case**: Simplify your program to the most basic version that should work. This means setting up a simple triangle with texture coordinates and trying to render that with your shaders. If this works, incrementally add back features until you find what breaks the rendering.

8. **OpenGL Errors**: Place `glGetError` calls after every significant OpenGL function to catch the exact location where an error might be occurring.

9. **Shader Compilation and Linking**: Double-check that the shaders are compiling and linking without errors.

If after all these steps the problem still persists, it might be helpful to look at the full shader code and the data being sent to the shaders to ensure everything is in order. Debugging rendering issues can be complex and often requires checking many different aspects of the rendering pipeline.