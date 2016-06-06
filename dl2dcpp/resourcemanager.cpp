#include <dl2dcpp/resourcemanager.h>

ResourceManager::ResourceManager()
{
	std::cout << "#######################" << std::endl;
	std::cout << "resourcemanager created" << std::endl;
}

ResourceManager::~ResourceManager()
{
	std::cout << "################ ResourceManager::delete ################" << std::endl;

	// delete shaders only in destructor. There might be an ubershader.
	// shaders
	std::cout << "---------- Delete Shaders ----------" << std::endl;
	std::map<std::string, Shader*>::iterator shad_it;
	for (shad_it = _shaders.begin(); shad_it != _shaders.end(); ++shad_it) {
		if (shad_it->second != NULL) {
			//std::cout << shad_it->first << " => " << shad_it->second << '\n';
			deleteShader(shad_it->first);
		}
	}
	_shaders.clear();

	// cleanup Textures and Meshes
	this->cleanup();

	std::cout << "resourcemanager empty" << std::endl;
	std::cout << "#####################" << std::endl;

	std::cout << "resourcemanager closed" << std::endl;
}

void ResourceManager::cleanup()
{
	std::cout << "################ ResourceManager::cleanup ################" << std::endl;
	// textures
	std::cout << "---------- Delete Textures ----------" << std::endl;
	std::map<std::string, Texture*>::iterator text_it;
	for (text_it = _textures.begin(); text_it != _textures.end(); ++text_it) {
		if (text_it->second != NULL) {
			//std::cout << text_it->first << " => " << text_it->second << '\n';
			deleteTexture(text_it->first);
		}
	}
	_textures.clear();
}

// Texture
Texture* ResourceManager::getTexture(const char * imagepath)
{
	if (_textures[imagepath] != NULL) {
		std::cout << "return existing resource: " << imagepath << " (texture)" << std::endl;
		return _textures[imagepath];
	}
	else {
		Texture* t = new Texture();
		t->loadTGA(imagepath);
		_textures[imagepath] = t;
		std::cout << "return new resource: " << imagepath << " (texture)" << std::endl;
		return t;
	}

	return NULL;
}

void ResourceManager::deleteTexture(const std::string& filename)
{
	delete _textures[filename];
	_textures[filename] = NULL;

	std::cout << "==> deleting resource: " << filename << " (texture)" << std::endl;
}

// Shaders
Shader* ResourceManager::getShader(const std::string& vs, const std::string& fs)
{
	std::string filename;
	filename = vs;
	std::string tmp("_");
	filename.append(tmp);
	filename.append(fs);
	if (_shaders[filename] != NULL) {
		//std::cout << "return existing resource: " << filename << " (shader)" << std::endl;
		return _shaders[filename];
	}
	else {
		Shader* s = new Shader();
		std::string fss = filename;
		fss.append(fs);
		std::string vss = filename;
		vss.append(vs);
		s->loadShaders(vss.c_str(), fss.c_str());
		_shaders[filename] = s;

		std::cout << "return new resource: " << filename << " (shader)" << std::endl;
		return s;
	}

	return NULL;
}

void ResourceManager::deleteShader(const std::string& shadername)
{
	std::string filename = filename;
	filename.append(shadername);

	delete _shaders[filename];
	_shaders[filename] = NULL;

	std::cout << "==> deleting resource: " << filename << " (shader)" << std::endl;
}
