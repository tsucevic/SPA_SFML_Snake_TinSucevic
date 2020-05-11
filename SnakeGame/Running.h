#pragma once
#include <SFML/Graphics.hpp>
#include "Keystroke.h"
#include "Cell.h"
#include <vector>
#include "Snake.h"
#include "Food.h"

using namespace std;
using namespace sf;

class Running
{
private:
	int numOfCells;
	RenderWindow* window;
	vector <vector <Cell>> grid;
	Snake snake;
	Food food;
	int score;

	vector<Vector2i> cellField;

	bool firstRun;

	void drawBoard();
	void drawWall();
	void moveSnake();
	void drawSnake();
	void drawFood();
	void pickup();
public:
	bool checkOver();
	void init(RenderWindow* window, int numOfCells);
	void draw();
	void keyPress(Keystroke key);
	int getScore();
};

