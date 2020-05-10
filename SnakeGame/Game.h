#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;
using namespace sf;
class Game
{

private:
	enum GameState
	{
		RUNNING, MENU, SETTINGS, OVER
	};
	GameState gameState;
	RenderWindow* window;
	Time updateTime = seconds(0.5f);
	string key;
	bool isNewPress;

public:
	Menu menu;
	Game(RenderWindow* window);
	void start();
	void update();
	void keyPress(string key);
};

