#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;

void keyCheck(Event& event, RenderWindow* window, Game* game)
{
	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			game->menu.moveUp();
			break;

		case sf::Keyboard::Down:
			game->menu.moveDown();
			break;

		case sf::Keyboard::Return:
			switch (game->menu.getPressedItem())
			{
			case 0:
				std::cout << "Play button has been pressed" << std::endl;
				break;
			case 1:
				std::cout << "Option button has been pressed" << std::endl;
				break;
			case 2:
				window->close();
				break;
			}
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

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			/*switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					game.menu.moveUp();
					break;

				case sf::Keyboard::Down:
					game.menu.moveDown();
					break;

				case sf::Keyboard::Return:
					switch (game.menu.getPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();

				break;

			}*/

			keyCheck(event, &window, &game);

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.update();
		window.display();
	}

	return 0;
}