// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <dl2dcpp/renderer.h>
#include <dl2dcpp/sprite.h>

#include <demo/map.h>

int main( void )
{
	Renderer renderer;
	Sprite* sprite = new Sprite("assets/testimage.tga", 128, 128);
	//Map* map = new Map();

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderer.renderSprite(sprite);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer.window()) == 0);

	delete sprite;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
