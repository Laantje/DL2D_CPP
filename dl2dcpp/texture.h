#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
	int			scroll;											// Used For Scrolling The Screen
	int			maxtokens;										// Keeps Track Of The Number Of Extensions Supported
	int			swidth;											// Scissor Width
	int			sheight;										// Scissor Height
};


GLuint		base;											// Base Display List For The Font

typedef struct												// Create A Structure
{
	GLubyte	*imageData;										// Image Data (Up To 32 Bits)
	GLuint	bpp;											// Image Color Depth In Bits Per Pixel.
	GLuint	width;											// Image Width
	GLuint	height;											// Image Height
	GLuint	texID;											// Texture ID Used To Select A Texture
} TextureImage;												// Structure Name

// Storage For One Texture
TextureImage textures[1];									

// Load a .BMP file using our custom loader
GLuint loadBMP_custom(const char * imagepath);

// Load a .TGA file
GLuint loadTGA(TextureImage *texture, const char * imagepath);

//// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library,
//// or do it yourself (just like loadBMP_custom and loadDDS)
//// Load a .TGA file using GLFW's own loader
//GLuint loadTGA_glfw(const char * imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);

#endif
