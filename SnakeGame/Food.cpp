#include "Food.h"

void Food::genColors()
{
	srand(time(nullptr));
	for (int i = 0; i < 6; i++)
	{
		Color color(rand() % 255, rand() % 255, rand() % 255);
		colors.push(color);
	}
}

void Food::genPositions()
{
	srand(time(nullptr));
	for (int i = 0; i < numOfCells; i++)
	{
		int randX = 1 + rand() % (numOfCells - 2);
		int randY = 1 + rand() % (numOfCells - 8);
		positions.push(Vector2i(randX, randY));
	}
}

void Food::init(int numOfCells)
{
	this->numOfCells = numOfCells;
	genPositions();
	genColors();
}

Color Food::getColor()
{
	return colors.front();
}

Vector2i Food::getPosition()
{
	return positions.top();
}

void Food::next()
{
	colors.push(colors.front());
	colors.pop();
	positions.pop();
	cout << "Next" << endl;
}
