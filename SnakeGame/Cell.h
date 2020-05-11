#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cell
{
private:
	RectangleShape drawable;
	RenderWindow* window;

	int size;
	int x;
	int y;

	Vector2i posInGrid;
	Vector2f posInWindow;

public:
	Cell();
	void init(RenderWindow* window, int numOfCells);
	void init(RenderWindow* window, int numOfCells, Vector2i posInGrid);

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	Vector2f getPosInWindow();
	void setPosInWindow(Vector2f pos);
	
	Vector2i getPosInGrid();
	void setPosInGrid(Vector2i pos);

	void setColor(Color color);
	void setColor(Color fillColor, Color outlineColor);

	void draw();
};

