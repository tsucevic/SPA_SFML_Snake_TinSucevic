#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
	//RenderWindow* window;
	int width;
	int height;
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

public:
	Menu();
	~Menu();

	void init(int width, int height);

	void draw(RenderWindow* window);
	void moveUp();
	void moveDown();
	int getPressedItem();
	
	int keyPress(string key);
};

