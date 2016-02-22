#include "demo/map.h"
#include <fstream>
#include "dl2dcpp/sprite.h"
#include "dl2dcpp/renderer.h"

//The dimensions of the level
const int LEVEL_WIDTH = 1024;
const int LEVEL_HEIGHT = 1024;

//Tile constants
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = 1024;
const int TOTAL_TILE_SPRITES = 28;

//The different tile sprites
const int TILE_GRASS = 0;
const int TILE_TREETRUNK = 1;
const int TILE_STONEB = 2;
const int TILE_STONET = 3;
const int TILE_STONER = 4;
const int TILE_STONEL = 5;
const int TILE_STONEUL = 6;
const int TILE_STONEUR = 7;
const int TILE_STONEBR = 8;
const int TILE_STONEBL = 9;
const int TILE_STONE = 10;
const int TILE_STONECRU = 11;
const int TILE_STONECLU = 12;
const int TILE_STONECLB = 13;
const int TILE_STONECRB = 14;
const int TILE_MUDR = 15;
const int TILE_MUDL = 16;
const int TILE_MUDT = 17;
const int TILE_MUDB = 18;
const int TILE_MUDBR = 19;
const int TILE_MUDBL = 20;
const int TILE_MUDTL = 21;
const int TILE_MUDTR = 22;
const int TILE_MUDCRT = 23;
const int TILE_MUDCLT = 24;
const int TILE_MUDCLB = 25;
const int TILE_MUDCRB = 26;
const int TILE_MUD = 27;

Map::Map() {
}

Map::~Map() {
	//delete tilesheet;
}

bool setTiles(Tile* tiles[])
{
	//Success flag
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("assets/tilemap.map");

	//If the map couldn't be loaded
	if (map == NULL)
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}

	else
	{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES))
			{
				tiles[i] = new Tile(x, y, tileType);
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}
			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if (x >= LEVEL_WIDTH)
			{
				//Move back
				x = 0;

				//Move to the next row
				y += TILE_HEIGHT;
			}
		}
		//Clip the sprite sheet
		if (tilesLoaded)
		{
			gTileClips[TILE_GRASS].x = 0;
			gTileClips[TILE_GRASS].y = 0;
			gTileClips[TILE_GRASS].w = TILE_WIDTH;
			gTileClips[TILE_GRASS].h = TILE_HEIGHT;

			gTileClips[TILE_GREEN].x = 0;
			gTileClips[TILE_GREEN].y = 80;
			gTileClips[TILE_GREEN].w = TILE_WIDTH;
			gTileClips[TILE_GREEN].h = TILE_HEIGHT;

			gTileClips[TILE_BLUE].x = 0;
			gTileClips[TILE_BLUE].y = 160;
			gTileClips[TILE_BLUE].w = TILE_WIDTH;
			gTileClips[TILE_BLUE].h = TILE_HEIGHT;

			gTileClips[TILE_TOPLEFT].x = 80;
			gTileClips[TILE_TOPLEFT].y = 0;
			gTileClips[TILE_TOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_LEFT].x = 80;
			gTileClips[TILE_LEFT].y = 80;
			gTileClips[TILE_LEFT].w = TILE_WIDTH;
			gTileClips[TILE_LEFT].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOMLEFT].x = 80;
			gTileClips[TILE_BOTTOMLEFT].y = 160;
			gTileClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_TOP].x = 160;
			gTileClips[TILE_TOP].y = 0;
			gTileClips[TILE_TOP].w = TILE_WIDTH;
			gTileClips[TILE_TOP].h = TILE_HEIGHT;

			gTileClips[TILE_CENTER].x = 160;
			gTileClips[TILE_CENTER].y = 80;
			gTileClips[TILE_CENTER].w = TILE_WIDTH;
			gTileClips[TILE_CENTER].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOM].x = 160;
			gTileClips[TILE_BOTTOM].y = 160;
			gTileClips[TILE_BOTTOM].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOM].h = TILE_HEIGHT;

			gTileClips[TILE_TOPRIGHT].x = 240;
			gTileClips[TILE_TOPRIGHT].y = 0;
			gTileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_RIGHT].x = 240;
			gTileClips[TILE_RIGHT].y = 80;
			gTileClips[TILE_RIGHT].w = TILE_WIDTH;
			gTileClips[TILE_RIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOMRIGHT].x = 240;
			gTileClips[TILE_BOTTOMRIGHT].y = 160;
			gTileClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;
		}
	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
}
