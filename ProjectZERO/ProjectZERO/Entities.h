#pragma once

#include<SFML\Graphics\Sprite.hpp>
#include<SFML\Graphics\RenderWindow.hpp>

//Movable "interface" is to be extended by the player class
class Movable {
public:
	virtual void move() final;
	virtual void moveObject() = 0;
};

//Visible "interface" is to be extended by all classes that contain sprites
class Visible {
private:
protected:
	sf::Sprite sprite;
public:
	virtual void draw(sf::RenderWindow* window) final;
	virtual void drawObject(sf::RenderWindow* window) = 0;
	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();
};

//Player class is the center of the hole game, it must implement Visible and Movable
class Player : public Visible, public Movable {
public:
	void drawObject(sf::RenderWindow* window);
	void moveObject();
};

//Interationable "interface" is to be extended by platforms and all the death/finish/start points classes
class Interactionable {
public:
	virtual void interact(Player* player) final;
	virtual void interactObject(Player* player) = 0;
};

//Platform class is represents floating tiles (can interact with the player)
class Platform : public Visible, public Interactionable{
private:
	int x, y;
public:
	Platform(int x, int y);
	void drawObject(sf::RenderWindow* window);
};

//Air class represents the empty tiles (can't interact with the player)
class Air : public Visible {
private:
	int x, y;
public:
	Air(int x, int y);
	void drawObject(sf::RenderWindow* window);
};

//Ground class represents the bottom tile's of a map (can interact with the player)
class Ground : public Visible, public Interactionable {
private:
	int x, y;
public:
	Ground(int x, int y);
	void drawObject(sf::RenderWindow* window);
};