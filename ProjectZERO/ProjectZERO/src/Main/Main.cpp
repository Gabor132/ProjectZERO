#include <SFML/Graphics.hpp>;
#include "../../src/Loader/MapGenerator.h";

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Project Zero");

	sf::Font font;
	font.loadFromFile("resources/Fonts/Xenotron.ttf");
	sf::Text text("Project ZERO", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Green);
	text.setPosition(250, 280);

	MapGenerator generator(std::string("/resources/maps/Map1.txt"));
	Map* mapa = generator.getMap();
	std::vector<sf::Sprite*>* tiles = mapa->getTiles();
	int k = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//window.clear();
		//window.draw(text);
		//window.draw(test);
		if (k == 0) {
			k++;
			for (int i = 0; i < tiles->size(); i++) {
				window.draw(*(tiles->at(i)));
			}
			window.display();
		}
	}

	return 0;
}