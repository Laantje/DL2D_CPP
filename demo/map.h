#ifndef MAP_H
#define MAP_H

#include <fstream>
#include "dl2dcpp/sprite.h"
#include "dl2dcpp/renderer.h"
#include <demo/tile.h>

class Map
{
public:
	Map();
	//virtual ~Map();

	int mapWidth;
	int mapHeight;

	std::string texturename() { return _texturename; };
	void texturename(std::string texturename) { _texturename = texturename; };

	int load_gl_textures();

	void drawTiles(void);

private:
	std::string _texturename;
};

#endif /* MAP_H */