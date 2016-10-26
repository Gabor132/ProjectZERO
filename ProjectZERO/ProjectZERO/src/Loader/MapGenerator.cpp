
#include "MapGenerator.h"

MapGenerator::MapGenerator(std::string mapFileName) {
	fopen_s(&mapFile,mapFileName.c_str(), "r");
	char c;
	std::ifstream stream;
	std::vector<sf::Sprite*> tiles;
	sf::Sprite *sprite;
	ObjectManager* oM = ObjectManager::getInstance();
	int i = 0, j = 0;
	std::cout << mapFileName << "\n";
	while (!stream.eof()) {
		stream >> c;
		switch (c) {
			case 1: {
				sprite = new sf::Sprite(oM->getTexture(ObjectManager::TextureType::GROUND));
			}break;
			case 2: {
				sprite = new sf::Sprite(oM->getTexture(ObjectManager::TextureType::PLATFORM));
			}break;
			default: {
				sprite = new sf::Sprite(oM->getTexture(ObjectManager::TextureType::AIR));
			}break;
		}
		sprite->setPosition(i, j);
		tiles.push_back(sprite);
		i+=40;
		if (i >= 800) {
			i = 0;
			j+=40;
		}
	}
	this->map = new Map(&tiles);
	fclose(mapFile);
}

Map* MapGenerator::getMap() {
	return this->map;
}

Map::Map(std::vector<sf::Sprite*>* tiles) {
	this->tiles = tiles;
}

std::vector<sf::Sprite*>* Map::getTiles() {
	return this->tiles;
}