#include "Settings.h"

void Settings::init(int width, int height)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}

	numOfCells = 50;

	stringstream ss;
	ss << "Cells: " << numOfCells;

	//play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString(ss.str());
	menu[0].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	//settings
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Menu");
	menu[1].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

void Settings::draw(RenderWindow* window)
{
	stringstream ss;
	ss << "Cells: " << numOfCells;
	menu[0].setString(ss.str());
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

void Settings::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Settings::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Settings::increase()
{
	numOfCells += 5;
}

void Settings::decrease()
{
	numOfCells -= 5;
}

int Settings::getPressedItem()
{
	return selectedItemIndex;
}

int Settings::keyPress(Keystroke key)
{
	switch (key.value)
	{
	case sf::Keyboard::Up:
		moveUp();
		return 4;
		break;

	case sf::Keyboard::Down:
		moveDown();
		return 4;
		break;
		
	case sf::Keyboard::Right:
		increase();
		return 4;
		break;
		
	case sf::Keyboard::Left:
		decrease();
		return 4;
		break;

	case sf::Keyboard::Return:
		switch (getPressedItem())
		{

		case 1:
			std::cout << "Menu button has been pressed" << std::endl;
			return 1;
			break;

		default:
			break;
		}

	default:
		break;
	}
}

int Settings::getNumber()
{
	return numOfCells;
}
