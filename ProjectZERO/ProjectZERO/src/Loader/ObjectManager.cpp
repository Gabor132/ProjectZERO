
#include "ObjectManager.h";

ObjectManager::ObjectManager() {
	std::cout << "LOADING TEXTURES\n";
	textureManager.LoadResource(TextureType::GROUND, groundPath);
	textureManager.LoadResource(TextureType::PLATFORM, platformPath);
	textureManager.LoadResource(TextureType::AIR, airPath);
	std::cout << "FINISHED\n";
}

sf::Texture& ObjectManager::getTexture(TextureType textureType) {
	std::cout << "RETREAVING TEXTURE "<<textureType<<"\n";
	return textureManager.GetResource(textureType);
}

ObjectManager* ObjectManager::instance;