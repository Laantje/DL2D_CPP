#ifndef MAP_H
#define MAP_H

#include "demo/tile.h"

class Map
{
public:
	Map();
	virtual ~Map();

private:
//	Sprite* tilesheet;
};

//Sets tiles from tile map
bool setTiles(Tile *tiles[]);

#endif /* MAP_H */