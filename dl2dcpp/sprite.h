#ifndef SPRITE_H
#define SPRITE_H

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

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	GLuint texture() { return _texture; };
	GLuint vertexbuffer() { return _vertexbuffer; };
	GLuint uvbuffer() { return _uvbuffer; };

	float pivotx;
	float pivoty;
	float uvdimx;
	float uvdimy;
	float uvoffsetx;
	float uvoffsety;

	int frame(int f);
	int frame() { return _frame; };

	void SetupSprite(std::string filename, int height, int width, float pivotx, float pivoty, float uvwidth, float uvheight);

private:
	int _frame;

	GLuint _texture;
	GLuint _vertexbuffer;
	GLuint _uvbuffer;

	void generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv);
};

#endif /* SPRITE_H */
