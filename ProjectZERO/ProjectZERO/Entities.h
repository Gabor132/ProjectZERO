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
public:
	virtual void draw(sf::RenderWindow* window) final;
	virtual void drawObject(sf::RenderWindow* window) = 0;
};

//Player class is the center of the hole game, it must implement Visible and Movable
class Player : public Visible, public Movable {
private:
	sf::Sprite sprite;

public:
	void drawObject(sf::RenderWindow* window);
	void moveObject();
	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();
};

//Interationable "interface" is to be extended by platforms and all the death/finish/start points classes
class Interactionable {
public:
	virtual void interact(Player* player) final;
	virtual void interactObject(Player* player) = 0;
};