#include "HighScores.h"

void HighScores::init(int width, int height)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}
	savior.loadScores();
	scores = savior.getHighScoreList();
	//settings
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Menu");
	menu[0].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	int i = 0;
	for (auto it = scores.begin(); it != scores.end(); ++it)
	{
		stringstream ss;
		ss << "ID: " << it->ID << " SCORE: " << it->score;
		menu[i].setFont(font);
		menu[i].setFillColor(Color::White);
		menu[i].setString(ss.str());
		menu[i].setPosition(Vector2f((width / 9) * 4, height / (MAX_NUMBER_OF_ITEMS + 1) * i+1));
		i++;
	}


	selectedItemIndex = 1;
}

void HighScores::draw(RenderWindow* window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

int HighScores::getPressedItem()
{
	return selectedItemIndex;
}

int HighScores::keyPress(Keystroke key)
{
	switch (key.value)
	{
	case sf::Keyboard::Return:
		switch (getPressedItem())
		{

		case 0:
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
