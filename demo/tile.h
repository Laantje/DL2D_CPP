#ifndef TILE_H
#define TILE_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <dl2dcpp\sprite.h>

class Tile
{
public:
	Tile(); ///< @brief Constructor of an Entity
	virtual ~Tile(); ///< @brief Destructor of an Entity

	Sprite* sprite() { return _sprite; };
	void addSpriteSheet(const std::string& filename, int u, int v);

private:
	Sprite* _sprite; ///< @brief The _sprite of this Entity

	void deleteSprite() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	};
};

#endif /* TILE_H */
