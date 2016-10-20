#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Application
{
	sf::Text *text;
	sf::RenderWindow *window;
	
public :
	

	Application();
	virtual void processInput();
	virtual void renderFrame();
	virtual void updateFrame();
	virtual void run();
};