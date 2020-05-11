#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Keystroke.h"


using namespace std;

void keyCheck(Event& event, RenderWindow* window, Game* game)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			game->keyPress(sf::Keyboard::Up);
			break;

		case sf::Keyboard::Down:
			game->keyPress(sf::Keyboard::Down);
			break;

		case sf::Keyboard::Left:
			game->keyPress(sf::Keyboard::Left);
			break;

		case sf::Keyboard::Right:
			game->keyPress(sf::Keyboard::Right);
			break;

		case sf::Keyboard::Escape:
			game->keyPress(sf::Keyboard::Escape);
			break;

		case sf::Keyboard::Return:
			game->keyPress(sf::Keyboard::Return);
			break;
		}

		break;

	case sf::Event::Closed:
		window->close();
		break;

	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Snake");
	window.setFramerateLimit(60);
	Game game(&window);

	Clock frameClock;
	Time updateTime = seconds(0.2f);
	Time currTime;

 	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Checks which key was pressed and sends it to the game.
			keyCheck(event, &window, &game); 

			if (event.type == sf::Event::Closed)
				window.close();
		}
		currTime = frameClock.getElapsedTime();
		if (currTime >= updateTime)
		{
			window.clear();
			game.update();
			window.display();
			frameClock.restart();
		};
	}

	return 0;
}