#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Keystroke.h"
#include <sstream>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2

class Settings
{
private:
	int width;
	int height;
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

	int numOfCells;

	void moveUp();
	void moveDown();
	void increase();
	void decrease();

public:
	void init(int width, int height);

	void draw(RenderWindow* window);
	int getPressedItem();

	int keyPress(Keystroke key);

	int getNumber();
};

