#include "Application.h"
#include <SFML/Window.hpp>
Application::Application()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Project Zero");
	
}
void Application::run()
{
	sf::Font font;
	font.loadFromFile("resources/Fonts/Xenotron.ttf");
	text = new sf::Text("Project ZERO", font);
	text->setCharacterSize(30);
	text->setStyle(sf::Text::Bold);
	text->setFillColor(sf::Color::Green);
	text->setPosition(250, 280);
	
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		processInput();
		updateFrame();
		renderFrame();
		
	}
}
void Application::renderFrame()
{
	window->clear();
	window->draw(*text);
	window->display();
}
void Application::updateFrame()
{

}
void Application::processInput()
{

}