
#include "Entities.h"

 void Visible::draw(sf::RenderWindow& window) {
	 drawObject(window);
 }

 void Visible::setSprite(sf::Sprite sprite) {
	 this->sprite = sprite;
 }
	
 sf::Sprite Visible::getSprite() {
	 return this->sprite;
 }