#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Keystroke.h"
#include <sstream>
#include "SaveHighScores.h"

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 6

class HighScores
{
private:
	int width;
	int height;
	int selectedItemIndex;

	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

	SaveHighScores savior;
	list<HighScore> scores;

public:
	void init(int width, int height);

	void draw(RenderWindow* window);
	int getPressedItem();

	int keyPress(Keystroke key);

};