#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <dl2dcpp/shader.h>
#include <dl2dcpp/texture.h>

/// @brief The ResourceManager class makes sure resources are loaded from disk only once.
class ResourceManager
{
public:
	ResourceManager(); ///< @brief Constructor of the ResourceManager
	virtual ~ResourceManager(); ///< @brief Destructor of the ResourceManager

								/// @brief get a Texture (from disk if need be)
								/// @param filename the path to the TGA file
								/// @param filter the filtering of the Texture
								/// @param wrap the UV wrapping of the Texture
								/// @return Texture* a pointer to a Texture, created from an image file (.tga only).
	Texture* getTexture(const char * imagepath);
	/// @brief Generate a Sprite Mesh
	/// @param width the width of the Sprite
	/// @param height the height of the Sprite
	/// @param pivotx the X component of the pivotpoint of the Sprite
	/// @param pivoty the Y component of the pivotpoint of the Sprite
	/// @param uvwidth the UV width of the SpriteSheet
	/// @param uvheight the UV height of the SpriteSheet
	/// @param circle generate custom Mesh or Circle (0=square Sprite, 6=hexagon)
	/// @param which if a segmentmesh, which segemnt to create (single triangle)
	/// @return Mesh* a pointer to the generated Mesh
	Shader* getShader(const std::string& vs, const std::string& fs);
	/// @brief clean up resources
	/// @return void
	void cleanup();

private:
	void deleteTexture(const std::string& filename);
	void deleteShader(const std::string& shadername);

	std::map<std::string, Texture*> _textures; ///< @brief a map of textures
	std::map<std::string, Shader*> _shaders; ///< @brief a map of shaders
};

#endif /* RESOURCEMANAGER_H */
