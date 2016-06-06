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
	//Sprite* sprite = new Sprite();
	//sprite->SetupSprite("assets/tilesheet.tga", 32, 32, 0.5f, 0.5f, 0.125f, 0.125f, 0);

	Texture* t = new Texture;
	t->loadTGA("assets/tilesheet.tga");
}

/*Map::~Map() {
	delete sprite;
}*/

void Map::drawTiles(void) { //our function to draw the tiles
	for (int i = 0; i < 32; i++) //loop through the height of the map
	{
		for (int j = 0; j < 32; j++) //loop through the width of the map
		{
			if (cMap[i][j] == 0)
			{
				Tile* grass = new Tile;
			}
			else if (cMap[i][j] == 1)
			{
				Tile* tree = new Tile;
			}
			else if (cMap[i][j] == 2)
			{
				Tile* stoneD = new Tile;
			}
			else if (cMap[i][j] == 3)
			{
				Tile* stoneU = new Tile;
			}
			else if (cMap[i][j] == 4)
			{
				Tile* stoneR = new Tile;
			}
			else if (cMap[i][j] == 5)
			{
				Tile* stoneL = new Tile;
			}
			else if (cMap[i][j] == 6)
			{
				Tile* stoneLU = new Tile;
			}
			else if (cMap[i][j] == 7)
			{
				Tile* stoneRU = new Tile;
			}
			else if (cMap[i][j] == 8)
			{
				Tile* stoneRD = new Tile;
			}
			else if (cMap[i][j] == 9)
			{
				Tile* stoneLD = new Tile;
			}
			else if (cMap[i][j] == 10)
			{
				Tile* stone = new Tile;
			}
			else if (cMap[i][j] == 11)
			{
				Tile* stoneRUC = new Tile;
			}
			else if (cMap[i][j] == 12)
			{
				Tile* stoneLUC = new Tile;
			}
			else if (cMap[i][j] == 13)
			{
				Tile* stoneRDC = new Tile;
			}
			else if (cMap[i][j] == 14)
			{
				Tile* stoneLDC = new Tile;
			}
			else if (cMap[i][j] == 15)
			{
				Tile* dirtR = new Tile;
			}
			else if (cMap[i][j] == 16)
			{
				Tile* dirtL = new Tile;
			}
			else if (cMap[i][j] == 17)
			{
				Tile* dirtU = new Tile;
			}
			else if (cMap[i][j] == 18)
			{
				Tile* dirtD = new Tile;
			}
			else if (cMap[i][j] == 19)
			{
				Tile* dirtRD = new Tile;
			}
			else if (cMap[i][j] == 20)
			{
				Tile* dirtLD = new Tile;
			}
			else if (cMap[i][j] == 21)
			{
				Tile* dirtLU = new Tile;
			}
			else if (cMap[i][j] == 22)
			{
				Tile* dirtRU = new Tile;
			}
			else if (cMap[i][j] == 23)
			{
				Tile* dirtRUC = new Tile;
			}
			else if (cMap[i][j] == 24)
			{
				Tile* stoneU = new Tile;
			}
			else if (cMap[i][j] == 25)
			{
				Tile* stoneU = new Tile;
			}
			else if (cMap[i][j] == 26)
			{
				Tile* stoneU = new Tile;
			}
			else if (cMap[i][j] == 27)
			{
				Tile* stoneU = new Tile;
			}
			else //otherwise
			{
				//glBindTexture(GL_TEXTURE_2D, texture2); //bind our dirt texture to our shape
			}

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
