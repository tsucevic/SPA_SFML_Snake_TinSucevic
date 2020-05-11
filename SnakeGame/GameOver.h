#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Keystroke.h"
#include <sstream>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class GameOver
{
private:
	int width;
	int height;
	int selectedItemIndex;

	int score;
	int id;

	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

	void moveUp();
	void moveDown();
	void increase();
	void decrease();

public:
	void init(int width, int height);

	void draw(RenderWindow* window);
	int getPressedItem();

	int keyPress(Keystroke key);

	void setScore(int score);
};