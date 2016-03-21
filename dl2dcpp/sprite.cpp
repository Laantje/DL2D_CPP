#include "sprite.h"

Sprite::Sprite()
{
	pivotx = 0.5f;
	pivoty = 0.5f;
	uvdimx = 1.0f;
	uvdimy = 1.0f;
	uvoffsetx = 0.0f;
	uvoffsety = 0.0f;
	_frame = 0;
}

void Sprite::SetupSprite(std::string filename, int width, int height, float pivotx, float pivoty, float uvwidth, float uvheight)
{
	uvdimx = uvwidth;
	uvdimy = uvheight;

	std::string texture_file = filename;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;

	// Load the texture (see: texture.h/cpp)
	_texture = loadTGA(texture_file.c_str());

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	int sprite_width = width;
	int sprite_height = height;

	// first triangle
	vertices.push_back(glm::vec3(-width * pivotx, -height * pivoty, 0.0f));
	vertices.push_back(glm::vec3(-width * pivotx, height - (height * pivoty), 0.0f));
	vertices.push_back(glm::vec3(width - (width * pivotx), height - (height * pivoty), 0.0f));
	// second triangle
	vertices.push_back(glm::vec3(width - (width * pivotx), height - (height * pivoty), 0.0f));
	vertices.push_back(glm::vec3(width - (width * pivotx), -height * pivoty, 0.0f));
	vertices.push_back(glm::vec3(-width * pivotx, -height * pivoty, 0.0f));

	// uvs for first triangle
	uvs.push_back(glm::vec2(0.0f, uvheight));
	uvs.push_back(glm::vec2(0.0f, 0.0f));
	uvs.push_back(glm::vec2(uvwidth, 0.0f));
	// uvs for second triangle
	uvs.push_back(glm::vec2(uvwidth, 0.0f));
	uvs.push_back(glm::vec2(uvwidth, uvheight));
	uvs.push_back(glm::vec2(0.0f, uvheight));

	this->generateBuffers(vertices, uvs);
}

Sprite::~Sprite()
{
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_uvbuffer);
}

void Sprite::generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv)
{
	//create GLuint _vertexbuffer;
	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(glm::vec3), &vertex[0], GL_STATIC_DRAW);

	//create GLuint _normalbuffer;
	//glGenBuffers(1, &_normalbuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, _normalbuffer);
	//glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(glm::vec3), &normal[0], GL_STATIC_DRAW);

	//create GLuint _uvbuffer;
	glGenBuffers(1, &_uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(glm::vec2), &uv[0], GL_STATIC_DRAW);
}

int Sprite::frame(int f)
{
	int w = 1.0f / uvdimx;
	int h = 1.0f / uvdimy;

	if (f >= w*h) {
		_frame = 0;
		return _frame;
	}

	int ypos = f / w;
	int xpos = f%w;

	uvoffsetx = xpos * uvdimx;
	uvoffsety = ypos * uvdimy;

	_frame = f;

	return _frame;
}
