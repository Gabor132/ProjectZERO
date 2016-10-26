#pragma once

#include<SFML\Graphics.hpp>
#include "ObjectManager.h"
#include <fstream>

class Map {
private:
	std::vector<sf::Sprite*> *tiles;
public:
	Map(std::vector<sf::Sprite*>* tiles);
	std::vector<sf::Sprite*>* getTiles();
};

class MapGenerator {
private:
	FILE *mapFile;
	Map* map;
public:
	MapGenerator(std::string mapFileName);
	Map* getMap();
};
