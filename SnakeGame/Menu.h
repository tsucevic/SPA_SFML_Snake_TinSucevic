#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Keystroke.h"

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
private:
	int width;
	int height;
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

public:
	void init(int width, int height);

	void draw(RenderWindow* window);
	void moveUp();
	void moveDown();
	int getPressedItem();
	
	int keyPress(Keystroke key);
};

