#ifndef MAP_H
#define MAP_H

#include "demo/map.h"
#include <fstream>
#include "dl2dcpp/sprite.h"
#include "dl2dcpp/renderer.h"
#include <demo/tile.h>

class Map
{
public:
	Map();
	virtual ~Map();

	void drawTiles(void);

private:
};

#endif /* MAP_H */