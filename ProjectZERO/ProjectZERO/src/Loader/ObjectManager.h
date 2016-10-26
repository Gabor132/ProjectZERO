#pragma once

#include "ResourceManager.h"
#include <SFML\Graphics.hpp>

class ObjectManager {
public:
	enum TextureType {
		PLATFORM, AIR, GROUND
	};
	static ObjectManager* ObjectManager::getInstance() {
		if (!instance) {
			instance = new ObjectManager();
		}
		return instance;
	}
	sf::Texture& getTexture(TextureType textureType);
private:
	ResourceManager<TextureType, sf::Texture> textureManager;
	const char* groundPath = "resources/sprites/png/ground.png";
	const char* platformPath = "resources/sprites/png/platform.png";
	const char* airPath = "resources/sprites/png/air.png";
	static ObjectManager* instance;
	ObjectManager();
};
