#include <SFML/Graphics.hpp>
#include "C:\Users\andrei\Source\Repos\ProjectZERO\ProjectZERO\ProjectZERO\Application.h"
int main()
{
	Application a; //new way to start main
	a.run();
	/*sf::RenderWindow window(sf::VideoMode(800, 600), "Project Zero"); 

	sf::Font font;
	font.loadFromFile("resources/Fonts/Xenotron.ttf");
	sf::Text text("Project ZERO", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Green);
	text.setPosition(250, 280);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}*/
	
	return 0;
}