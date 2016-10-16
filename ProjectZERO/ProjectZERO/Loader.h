#pragma once

#include <hash_set>

//Loader is a singleton class that handles the sprite loading and map creation
class Loader {
private:
	static Loader* instance;
	Loader();
public:
	enum SpritePath{ PLAYER, PLATFORM, GROUND, FINISH, START};

	static Loader getInstance();
};