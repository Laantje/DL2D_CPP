#ifndef SPRITE_H

//#include


class Sprite
{
public:
	Sprite(std::string filename);
	virtual ~Sprite();

	Gluint texture() { return _texture };
	Gluint vertexbuffer() { return _vertexbuffer };
	Gluint uvbuffer() { return _uvbuffer };
};

#define SPRITE_H

#endif
