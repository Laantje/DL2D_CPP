#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <dl2dcpp/shader.h>
#include <dl2dcpp/sprite.h>
#include <dl2dcpp/texture.h>
#include <dl2dcpp/camera.h>

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void renderSprite(Sprite* sprite, float posX, float posY);
	GLFWwindow* window() { return _window; };

private:
	int init();

	//Gluints
	GLuint programID;
	GLuint matrixID;
	GLuint textureID;
	GLuint vertexPosition_modelspaceID;
	GLuint vertexUVID;

	//Window
	GLFWwindow* _window;
	int window_width;
	int window_height;

	//Shaders
	std::string fragment_shader;
	std::string vertex_shader;

	glm::mat4 ProjectionMatrix;
};

#endif /* RENDERER_H */