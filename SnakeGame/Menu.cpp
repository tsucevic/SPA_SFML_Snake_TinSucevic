#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::init(int width, int height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		
	}

	//play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1)); 

	//settings
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Settings");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	//exit
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

void Menu::draw(RenderWindow* window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

int Menu::getPressedItem()
{
	return selectedItemIndex;
}

int Menu::keyPress(string key)
{
	switch (key)
	{
	case "UP":
		moveUp();
		return 4;
		break;

	case sf::Keyboard::Down:
		moveDown();
		return 4;
		break;

	case sf::Keyboard::Return:
		switch (getPressedItem())
		{
		case 0:
			std::cout << "Play button has been pressed" << std::endl;
			return 0;
			break;
		case 1:
			std::cout << "Option button has been pressed" << std::endl;
			return 1;
			break;
		case 2:
			return 2;
			break;
		}
	default:
		break;
	}
}
