#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <glfw3.h>

class Texture
{
public:
	Texture(); ///< @brief Constructor of the Texture
	virtual ~Texture(); ///< @brief Destructor of the Texture

	GLuint getGLTexture() { return _gltexture[0]; };

	// Load a .BMP file using our custom loader
	GLuint loadBMP_custom(const char * imagepath);

	// Load a .TGA file
	GLuint loadTGA(const char * imagepath);

	//// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library,
	//// or do it yourself (just like loadBMP_custom and loadDDS)
	//// Load a .TGA file using GLFW's own loader
	//GLuint loadTGA_glfw(const char * imagepath);

	// Load a .DDS file using GLFW's own loader
	GLuint loadDDS(const char * imagepath);

	int width() { return _width; };
	/// @brief get the height of the OpenGL texture
	/// @return int _height
	int height() { return _height; };
	/// @brief bytes per pixel. 3=RGB, 4=RGBA.
	/// @return int _depth
	int depth() { return _depth; };

private:

	int _width;
	/// @brief the height of the file
	int _height;
	/// @brief the color depth of the pixels
	int _depth;
	/// @brief a number of texture names (1 for now)
	GLuint _gltexture[1];
};

#endif
