
#include "Entities.h"

void Player::drawObject(sf::RenderWindow* window) {
	window->draw(this->sprite);
}

void Player::moveObject() {

}

void Player::setSprite(sf::Sprite sprite) {
	this->sprite = sprite;
}

sf::Sprite Player::getSprite() {
	return this->sprite;
}
