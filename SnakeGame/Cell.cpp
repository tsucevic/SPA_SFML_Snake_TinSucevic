#include "Cell.h"

Cell::Cell()
{
}

void Cell::init(RenderWindow* window, int numOfCells)
{
	this->window = window;
	size = ((this->window->getSize().x) * 0.91) / numOfCells;
	drawable.setOutlineThickness(1);
	drawable.setSize(Vector2f(size, size));
}

void Cell::init(RenderWindow* window, int numOfCells, Vector2i posInGrid)
{
	init(window, numOfCells);

	setPosInGrid(posInGrid);

	float winX = 0;
	float winY = 0;

	winX = ((this->window->getSize().x) * 0.045) + size*(posInGrid.x+1);
	winY = ((this->window->getSize().y) * 0.045) + size*(posInGrid.y+1);


	setPosInWindow(Vector2f(winX, winY));
}

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}

void Cell::setX(int x)
{
	this->x = x;
	setPosInGrid(Vector2i(this->x, this->y));
}

void Cell::setY(int y)
{
	this->y = y;
	setPosInGrid(Vector2i(this->x, this->y));
}

Vector2f Cell::getPosInWindow()
{
	return posInWindow;
}

void Cell::setPosInWindow(Vector2f pos)
{
	posInWindow = pos;
}

Vector2i Cell::getPosInGrid()
{
	return posInGrid;
}

void Cell::setPosInGrid(Vector2i pos)
{
	posInGrid = pos;
	x = posInGrid.x;
	y = posInGrid.y;

	float winX = ((this->window->getSize().x) * 0.045) + size * (posInGrid.x + 1);
	float winY = ((this->window->getSize().y) * 0.045) + size * (posInGrid.y + 1);


	setPosInWindow(Vector2f(winX, winY));
}

void Cell::setColor(Color color)
{
	drawable.setFillColor(color);
}

void Cell::setColor(Color fillColor, Color outlineColor)
{
	setColor(fillColor);
	drawable.setOutlineColor(outlineColor);
}

void Cell::draw()
{
	drawable.setPosition(posInWindow);
	window->draw(drawable);
}
