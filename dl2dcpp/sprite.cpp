#include "sprite.h"

Sprite::Sprite(std::string filename, int width, int height, bool spritesheet, int frames, int cframe)
{
	std::string texture_file = filename;

	// Load the texture (see: texture.h/cpp)
	_texture = loadTGA(texture_file.c_str());

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	int sprite_width = width;
	int sprite_height = height;
	GLfloat g_vertex_buffer_data[] = {
		0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
		-0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
		-0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		-0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		0.5f * sprite_width, -0.5f * sprite_height, 0.0f
	};

		int number_of_frames = frames;
		int current_frame = cframe;

		double cell_division = 1.0 / number_of_frames;
		double x_cell = current_frame * cell_division;
		double x_cell2 = (current_frame * cell_division) + cell_division;

		glBegin(GL_QUADS);
		glTexCoord2d(x_cell, 0.0);
		glVertex3i(0, 0, 0);
		glTexCoord2d(x_cell2, 0.0);
		glVertex3i(sprite_width, 0, 0);
		glTexCoord2d(x_cell2, 1.0);
		glVertex3i(sprite_width, sprite_height, 0);
		glTexCoord2d(x_cell, 1.0);
		glVertex3i(0, sprite_height, 0);
		glEnd();

	// Two UV coordinates for each vertex.
	/*GLfloat g_uv_buffer_data[] = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};*/

	GLfloat g_uv_buffer_data[] = {
			0.125f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.875f,
			0.0f, 0.875f,
			0.125f, 0.875f,
			0.125f, 1.0f
		};
	

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &_uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

Sprite::~Sprite()
{
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_uvbuffer);
}
