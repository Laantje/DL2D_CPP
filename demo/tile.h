#ifndef TILE_H
#define TILE_H

// Include GLFW
#include <glfw3.h>

class Tile
{
public:
	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	void render(glRectf& camera);

	//Get the tile type
	int getType();

	//Get the collision box
	glRectf getBox();

private:
	//The attributes of the tile
	
	glRectf mBox;

	//The tile type
	int mType;
};

#endif /* TILE_H */
