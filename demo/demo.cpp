// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <dl2dcpp/renderer.h>
#include <dl2dcpp/sprite.h>
#include <demo/tile.h>

#include <demo/map.h>

int main( void )
{
	Renderer renderer;
	//Sprite* sprite = new Sprite();
	//sprite->addSprite("")
	//sprite->frame(56);
	//sprite->SetupSprite("assets/tilesheet.tga", 32, 32, 0.5f, 0.5f, 0.125f, 0.125f);
	Tile* tile = new Tile;
	tile->addSpriteSheet("assets/tilesheet.tga", 8, 8, 57);
	//Map* map = new Map;
	//map->drawTiles();

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderer.renderSprite(tile->sprite(), 600.0f, 500.0f);

		/*if (glfwGetKey(renderer.window(), GLFW_KEY_UP) == GLFW_PRESS) {
			std::cout << "Pressed up";
			if (tile->sprite()->_frame < 64) {
				tile->sprite()->frame(tile->sprite()->_frame + 1);
			}
			else if (tile->sprite()->_frame == 64) {
				tile->sprite()->frame(0);
			}
		}

		if (glfwGetKey(renderer.window(), GLFW_KEY_DOWN) == GLFW_PRESS) {
			std::cout << "Pressed down";
			if (tile->sprite()->_frame > 0) {
				tile->sprite()->frame(tile->sprite()->_frame - 1);
			}
			else if (tile->sprite()->_frame == 0) {
				tile->sprite()->frame(64);
			}
		}*/

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer.window()) == 0);

	delete tile;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
