#include "GameOver.h"
void GameOver::moveUp()
{
	if (selectedItemIndex - 1 >= 1)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
void GameOver::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
void GameOver::increase()
{
	if (selectedItemIndex == 1)
	{
		id += 1;
	}
}
void GameOver::decrease()
{
	if (selectedItemIndex == 1)
	{
		id -= 1;
	}
}
void GameOver::init(int width, int height)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}


	stringstream ss;
	ss << "Score: " << score;
	//play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::White);
	menu[0].setString(ss.str());
	menu[0].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	id = 0;
	stringstream ss2;
	ss2 << "ID: " << id;
	//settings
	menu[1].setFont(font);
	menu[1].setFillColor(Color::Red);
	menu[1].setString(ss.str());
	menu[1].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	//settings
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Menu");
	menu[2].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	

	selectedItemIndex = 1;
}

void GameOver::draw(RenderWindow* window)
{
	stringstream ss;
	ss << "Score: " << score;
	menu[0].setString(ss.str());
	stringstream ss2;
	ss2 << "ID: " << id;
	menu[1].setString(ss2.str());
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

int GameOver::getPressedItem()
{
	return selectedItemIndex;
}

int GameOver::keyPress(Keystroke key)
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
		savior.lsa(id, score);
		switch (getPressedItem())
		{

		case 2:
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
void GameOver::setScore(int score)
{
	this->score = score;
}

