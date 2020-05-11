#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Menu.h"
#include "Keystroke.h"
#include "Running.h"
#include "Settings.h"
#include "GameOver.h"

using namespace std;
using namespace sf;

class Game
{

private:
	enum GameState
	{
		RUNNING, MENU, SETTINGS, OVER, HIGH_SCORES
	};
	GameState gameState;
	RenderWindow* window;
	int numOfCells = 50;

	int score;
	
	Keystroke key;

	Menu menu;
	Settings settings;
	GameOver over;
	Running game;

public:
	Game(RenderWindow* window);
	void start();
	void update();
	void keyPress(Keyboard::Key key);
};

