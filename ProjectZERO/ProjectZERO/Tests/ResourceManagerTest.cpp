#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Green);

	ResourceManager<std::string, sf::Texture> textureManager;
	textureManager.LoadResource("apa", "C:/Users/andrei/Source/Repos/ProjectZERO/ProjectZERO/ProjectZERO/resources/sprites/png/ground.png");
	sf::Sprite test;
	test.setTexture(textureManager.GetResource("apa"));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(test);
		window.display();
	}

	return 0;
}