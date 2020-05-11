#include "Running.h"

void Running::init(RenderWindow* window, int numOfCells)
{
	firstRun = true;
	this->window = window;
	this->numOfCells = numOfCells;

	score = 0;
	
	for (int i = 0; i < numOfCells; i++)
	{
		grid.push_back(vector<Cell>());
		for (int j = 0; j < numOfCells; j++)
		{
			Cell temp;
			temp.init(window, numOfCells, Vector2i(i, j));
			grid[i].push_back(temp);
		}
	}

	srand(time(nullptr));
	int randX = 1 + rand() % (numOfCells-2);
	int randY = 1 + rand() % (numOfCells-8);

	snake.init(numOfCells, Vector2i(randX, randY));
	snake.enlarge();
	snake.enlarge();
	cellField = snake.getSnake();

	food.init(numOfCells);
}

void Running::drawBoard()
{
	for (int i = 0; i < numOfCells; i++)
	{
		for (int j = 0; j < numOfCells; j++)
		{
			grid[i][j].setColor(Color::Black,Color::Red);
		}
	}
}

void Running::drawWall()
{
	for (int i = 0; i < numOfCells; i++)
	{
		grid[i][0].setColor(Color::Red, Color::Red);
		grid[0][i].setColor(Color::Red, Color::Red);
	}
	for (int j = 0; j < numOfCells; j++)
	{
		grid[j][numOfCells-1].setColor(Color::Red, Color::Red);
		grid[numOfCells-1][j].setColor(Color::Red, Color::Red);
	}
}

void Running::moveSnake()
{
	snake.move();
	cellField = snake.getSnake();
}

bool Running::checkOver()
{
	Vector2i head = snake.getHead();
	int x = head.x;
	int y = head.y;
	if (x == 0 || x == numOfCells)
	{
		return true;
	}
	if (y == 0 || y == numOfCells)
	{
		return true;
	}
	if (snake.ateMyTail() && !firstRun)
	{
		return true;
	}

	firstRun = false;
	return false;
}

void Running::drawSnake()
{

	if (!checkOver())
	{
  		grid[cellField[0].x][cellField[0].y].setColor(Color::Yellow);
		for (int i = 1; i < cellField.size(); i++)
		{
			grid[cellField[i].x][cellField[i].y].setColor(Color::Green);
		}
	}
}

void Running::drawFood()
{
	grid[food.getPosition().x][food.getPosition().y].setColor(food.getColor());
}

void Running::pickup()
{
	if (snake.getHead() == food.getPosition())
	{
		snake.enlarge();
		food.next();
		score++;
	}
}

void Running::draw()
{

	drawBoard();
	drawWall();

	moveSnake();
	drawSnake();

	pickup();
	drawFood();

	for (int i = 0; i < numOfCells; i++)
	{
		for (int j = 0; j < numOfCells; j++)
		{
			grid[i][j].draw();
		}
	}
}

void Running::keyPress(Keystroke key)
{
	snake.keyPress(key);
}

int Running::getScore()
{
	return score;
}
