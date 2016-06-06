#ifndef SPRITE_H
#define SPRITE_H

#define SPRITEVERTEXSHADER "shaders/sprite.vert" ///< vertexshader name
#define SPRITEFRAGMENTSHADER "shaders/sprite.frag" ///< fragmentshader name
#define AUTOGENWHITE "#autogen-white-TGA#" ///< auto generated Texture

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <dl2dcpp/texture.h>
#include <dl2dcpp/shader.h>

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	std::string texturename() { return _texturename; };
	void texturename(std::string texturename) { _texturename = texturename; };

	GLuint texture() { return _texture; };
	GLuint vertexbuffer() { return _vertexbuffer; };
	GLuint uvbuffer() { return _uvbuffer; };

	std::string fragmentshader() { return _fragmentshader; };
	std::string vertexshader() { return _vertexshader; };
	void fragmentshader(std::string fragmentshader) { _fragmentshader = fragmentshader; };
	void vertexshader(std::string vertexshader) { _vertexshader = vertexshader; };

	float pivotx;
	float pivoty;
	float uvdimx;
	float uvdimy;
	float uvoffsetx;
	float uvoffsety;

	int frame(int f);
	int frame() { return _frame; };

	void SetupSprite(std::string filename, int height, int width, float pivotx, float pivoty, float uvwidth, float uvheight, int f);

private:
	int _frame;

	std::string _texturename;

	std::string _fragmentshader;
	std::string _vertexshader;

	GLuint _texture;
	GLuint _vertexbuffer;
	GLuint _uvbuffer;

	void generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv);
};

#endif /* SPRITE_H */
