#include "Game.h"

using namespace std;
using namespace sf;

// Constructor
Game::Game(RenderWindow* window)
{
	this->window = window;
	start();
}

// Load game and initilize menu
void Game::start()
{
	//gameState = RUNNING;
	gameState = MENU;
	menu.init(window->getSize().x, window->getSize().y);
	menu.draw(window);

	settings.init(window->getSize().x, window->getSize().y);
	over.init(window->getSize().x, window->getSize().y);
}

// Updates the screen based on gameState and keyStrokes
void Game::update()
{
	Event event;

	score = game.getScore();

	switch (gameState)
	{
	case Game::RUNNING:
		while (key.isNewPressed)
		{
			game.keyPress(key);
			key.isNewPressed = false;
		}
		game.draw();
		if (game.checkOver())
		{
			gameState = OVER;
			cout << "Over" << endl;
		}
		break;
	case Game::MENU:
		while (key.isNewPressed)
		{
			int chosenItem = menu.keyPress(key);
			switch (chosenItem)
			{
			case 0:
				gameState = RUNNING;
				game.init(window, settings.getNumber());
				break;
			case 1:
				gameState = SETTINGS;
				break;
			case 2:
				gameState = HIGH_SCORES;
				break;
			case 3:
				window->close();
				break;
			default:
				gameState = MENU;
				break;
			}
			key.isNewPressed = false;
		}
		menu.draw(window);
		break;
	case Game::SETTINGS:
		while (key.isNewPressed)
		{
			int chosenItem = settings.keyPress(key);
			switch (chosenItem)
			{
			case 1:
				gameState = MENU;
				break;
			default:
				gameState = SETTINGS;
				break;
			}
			key.isNewPressed = false;
		}
		settings.draw(window);
		break;
	case Game::OVER:
		while (key.isNewPressed)
		{
			int chosenItem = over.keyPress(key);
			switch (chosenItem)
			{
			case 1:
				gameState = MENU;
				break;
			default:
				gameState = OVER;
				break;
			}
			key.isNewPressed = false;
		}
		over.setScore(score);
		over.draw(window);
		break;
	case Game::HIGH_SCORES:
		break;
	default:
		break;
	}
}

// Saves keyPressed and says it was a new press.
void Game::keyPress(Keyboard::Key key)
{
	this->key.value = key;
	this->key.isNewPressed = true;
}
