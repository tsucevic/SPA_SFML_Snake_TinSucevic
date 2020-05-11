#pragma once
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Food
{
private:
	queue<Color> colors;
	stack<Vector2i> positions;
	int numOfCells;

	void genColors();
	void genPositions();

public:
	void init(int numOfCells);
	Color getColor();
	Vector2i getPosition();

	void next();
};

