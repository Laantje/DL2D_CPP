#include "demo/tile.h"

Tile::Tile()
{
	_sprite = NULL;
}

Tile::~Tile()
{
	deleteSprite();
}

void Tile::addSpriteSheet(const std::string& filename, int u, int v, int f)
{
	deleteSprite();
	_sprite = new Sprite();
	float uvwidth = 1.0f / u;
	float uvheight = 1.0f / v;
	_sprite->SetupSprite(filename, 32, 32, 0.5f, 0.5f, uvwidth, uvheight, f);
}
