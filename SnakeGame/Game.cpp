#include "Game.h"

using namespace std;
using namespace sf;

Game::Game(RenderWindow* window)
{
	this->window = window;
	start();
}

void Game::start()
{
	gameState = MENU;
	menu.init(window->getSize().x, window->getSize().y);
	menu.draw(window);
}

void Game::update()
{
	Event event;

	switch (gameState)
	{
	case Game::RUNNING:
		break;
	case Game::MENU:
		/*while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				int state = menu.keyPress(event);
				switch (state)
				{
				case 0:
					gameState = RUNNING;
					break;
				case 1:
					gameState = SETTINGS;
					break;
				case 2:
					window->close();
					break;
				default:
					gameState = MENU;
					break;
				}
			}
			menu.draw(window);
		}*/

		while (isNewPress)
		{
			int state = menu.keyPress(key);
			switch (state)
			{
			case 0:
				gameState = RUNNING;
				break;
			case 1:
				gameState = SETTINGS;
				break;
			case 2:
				window->close();
				break;
			default:
				gameState = MENU;
				break;
			}
		}

		menu.draw(window);
		break;
	case Game::SETTINGS:
		break;
	case Game::OVER:
		break;
	default:
		break;
	}
}

// koji key je stisnut i je li tek stisnut
void Game::keyPress(string key)
{
	this->key = key;
	isNewPress = true;
}


// Promijeniti keypress u enum classu koju svi imaju
// 