#pragma once
#include <vector>
#include "Keystroke.h"
#include <SFML/Graphics.hpp>
using namespace std;
class Snake
{
private:
	enum Orientation
	{
		UP = 2, 
		DOWN = 4, 
		LEFT = 3,
		RIGHT = 5
	};
	int numOfCells;
	int numOfFood;
	
	vector<sf::Vector2i> snake;

	Orientation orientation;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void moveParts();

public:
	void init(int numOfCells, sf::Vector2i head);

	vector<sf::Vector2i> getSnake();

	void keyPress(Keystroke key);

	void move();

	void enlarge();

	sf::Vector2i getHead();

	bool ateMyTail();
};

