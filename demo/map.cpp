#include "demo/map.h"

#define MAP_SIZEX 32
#define MAP_SIZEY 32

GLuint texture[28];

int cMap[32][32] = {
	{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 },
	{ 10,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,7,10 },
	{ 10,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,10 },
	{ 10,5,0,26,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,25,0,0,0,0,0,0,1,0,0,4,10 },
	{ 10,5,0,15,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,16,0,0,0,0,0,0,0,0,0,4,10 },
	{ 10,5,0,15,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,16,0,0,0,0,0,0,0,0,0,4,10 },
	{ 10,5,0,15,27,27,21,17,17,17,17,17,17,17,17,17,17,22,27,27,16,0,14,2,2,2,2,2,13,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,1,15,27,27,16,0,0,0,0,0,0,0,1,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,4,10,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,11,7,10,10,10,10,5,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,16,0,0,11,3,3,3,3,12,0,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,20,18,18,18,18,18,18,18,18,25,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,1,0,0,0,0,0,0,15,27,27,27,27,27,27,27,27,27,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,15,27,27,27,27,27,27,27,27,27,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,23,17,17,17,17,17,17,17,17,22,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,15,27,27,16,4,10 },
	{ 10,5,0,15,27,27,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,27,27,16,4,10 },
	{ 10,5,0,15,27,27,20,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,19,27,27,16,4,10 },
	{ 10,5,0,15,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,16,4,10 },
	{ 10,5,0,15,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,16,4,10 },
	{ 10,5,0,23,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,24,4,10 },
	{ 10,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,10 },
	{ 10,9,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,8,10 },
	{ 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 },
};

Map::Map() {
	_texturename = "assets/tilesheet.tga";

	mapWidth = 32;
	mapHeight = 32;
}

/*Map::~Map() {
	delete sprite;
}*/

void Map::drawTiles(void) { //our function to draw the tiles
	for (int i = 0; i < 32; i++) //loop through the height of the map
	{
		for (int j = 0; j < 32; j++) //loop through the width of the map
		{
			/*if (cMap[i][j] == 0)
			{
				Tile* grass = new Tile;
				grass->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 57);
			}
			else if (cMap[i][j] == 1)
			{
				Tile* tree = new Tile;
				tree->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 58);
			}
			else if (cMap[i][j] == 2)
			{
				Tile* stoneD = new Tile;
				stoneD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 59);
			}
			else if (cMap[i][j] == 3)
			{
				Tile* stoneU = new Tile;
				stoneU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 60);
			}
			else if (cMap[i][j] == 4)
			{
				Tile* stoneR = new Tile;
				stoneR->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 61);
			}
			else if (cMap[i][j] == 5)
			{
				Tile* stoneL = new Tile;
				stoneL->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 62);
			}
			else if (cMap[i][j] == 6)
			{
				Tile* stoneLU = new Tile;
				stoneLU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 63);
			}
			else if (cMap[i][j] == 7)
			{
				Tile* stoneRU = new Tile;
				stoneRU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 64);
			}
			else if (cMap[i][j] == 8)
			{
				Tile* stoneRD = new Tile;
				stoneRD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 49);
			}
			else if (cMap[i][j] == 9)
			{
				Tile* stoneLD = new Tile;
				stoneLD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 50);
			}
			else if (cMap[i][j] == 10)
			{
				Tile* stone = new Tile;
				stone->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 51);
			}
			else if (cMap[i][j] == 11)
			{
				Tile* stoneRUC = new Tile;
				stoneRUC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 52);
			}
			else if (cMap[i][j] == 12)
			{
				Tile* stoneLUC = new Tile;
				stoneLUC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 53);
			}
			else if (cMap[i][j] == 13)
			{
				Tile* stoneRDC = new Tile;
				stoneRDC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 54);
			}
			else if (cMap[i][j] == 14)
			{
				Tile* stoneLDC = new Tile;
				stoneLDC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 55);
			}
			else if (cMap[i][j] == 15)
			{
				Tile* dirtR = new Tile;
				dirtR->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 56);
			}
			else if (cMap[i][j] == 16)
			{
				Tile* dirtL = new Tile;
				dirtL->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 41);
			}
			else if (cMap[i][j] == 17)
			{
				Tile* dirtU = new Tile;
				dirtU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 42);
			}
			else if (cMap[i][j] == 18)
			{
				Tile* dirtD = new Tile;
				dirtD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 43);
			}
			else if (cMap[i][j] == 19)
			{
				Tile* dirtRD = new Tile;
				dirtRD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 44);
			}
			else if (cMap[i][j] == 20)
			{
				Tile* dirtLD = new Tile;
				dirtLD->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 45);
			}
			else if (cMap[i][j] == 21)
			{
				Tile* dirtLU = new Tile;
				dirtLU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 46);
			}
			else if (cMap[i][j] == 22)
			{
				Tile* dirtRU = new Tile;
				dirtRU->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 47);
			}
			else if (cMap[i][j] == 23)
			{
				Tile* dirtRUC = new Tile;
				dirtRUC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 48);
			}
			else if (cMap[i][j] == 24)
			{
				Tile* dirtLUC = new Tile;
				dirtLUC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 33);
			}
			else if (cMap[i][j] == 25)
			{
				Tile* dirtLDC = new Tile;
				dirtLDC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 34);
			}
			else if (cMap[i][j] == 26)
			{
				Tile* dirtLRC = new Tile;
				dirtLRC->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 35);
			}
			else if (cMap[i][j] == 27)
			{
				Tile* dirt = new Tile;
				dirt->sprite()->SetupSprite(_texturename, 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 36);
			}
			/*else //otherwise
			{
				//glBindTexture(GL_TEXTURE_2D, texture2); //bind our dirt texture to our shape
			}*/

			glPushMatrix(); //push the matrix so that our translations only affect
			glTranslatef(j, -i, 0); //translate the tile to where it should belong

			glBegin(GL_QUADS); //begin drawing our quads
			glTexCoord2d(0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0); //with our vertices we have to assign a texcoord

			glTexCoord2d(1.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0); //so that our texture has some points to draw to

			glTexCoord2d(1.0, 1.0);
			glVertex3f(1.0, 1.0, 0.0);

			glTexCoord2d(0.0, 1.0);
			glVertex3f(0.0, 1.0, 0.0);
			glEnd();
			glPopMatrix();
		}
	}
}
