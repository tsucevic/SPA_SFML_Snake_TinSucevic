#include "Snake.h"
using namespace std;

void Snake::moveUp()
{
	moveParts();
	snake[0].y--;
}

void Snake::moveDown()
{
	moveParts();
	snake[0].y++;
}

void Snake::moveLeft()
{
	moveParts();
	snake[0].x--;
}

void Snake::moveRight()
{
	moveParts();
	snake[0].x++;
}

void Snake::moveParts()
{
	if (snake.size() > 1)
	{
		for (int i = snake.size()-1; i != 0; i--)
		{
			snake[i].x = snake[(i - 1)].x;
			snake[i].y = snake[(i - 1)].y;
		}
	}
}

void Snake::init(int numOfCells, sf::Vector2i head)
{
	orientation = UP;
	snake.push_back(head);
}

vector<sf::Vector2i> Snake::getSnake()
{
	return snake;
}

void Snake::keyPress(Keystroke key)
{
	switch (key.value)
	{
	case sf::Keyboard::Up:
		if (orientation != DOWN) { orientation = UP; };
		break;
	case sf::Keyboard::Down:
		if (orientation != UP) { orientation = DOWN; };
		break;
	case sf::Keyboard::Left:
		if (orientation != RIGHT) { orientation = LEFT; };
		break;
	case sf::Keyboard::Right:
		if (orientation != LEFT) { orientation = RIGHT; };
		break;

	default:
		break;
	}
}

void Snake::move()
{
	switch (orientation)
	{
	case Snake::UP:
		moveUp();
		break;
	case Snake::DOWN:
		moveDown();
		break;
	case Snake::LEFT:
		moveLeft();
		break;
	case Snake::RIGHT:
		moveRight();
		break;
	default:
		break;
	}
}

void Snake::enlarge()
{
	int tailX = snake[snake.size() - 1].x;
	int tailY = snake[snake.size() - 1].y;
	snake.push_back(sf::Vector2i(tailX, tailY));
}

sf::Vector2i Snake::getHead()
{
	return snake[0];
}

bool Snake::ateMyTail()
{
	for (int i = 1; i < snake.size(); i++)
	{
		if (snake[0] == snake[i])
		{
			return true;
		}
	}
	return false;
}
