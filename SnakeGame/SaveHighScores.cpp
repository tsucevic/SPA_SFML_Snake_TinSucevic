#include "SaveHighScores.h"

void SaveHighScores::removeIfFull()
{
	/*sort(scores.begin(), scores.end(),
		[](HighScore const& s1, HighScore const& s2)
		{
			return s1.ID < s2.ID;
		}
	);*/

	scores.sort([](HighScore const& s1, HighScore const& s2)
		{
			return s1.ID < s2.ID;
		});

	while (scores.size() > 5)
	{
		scores.pop_front();
	}
}

SaveHighScores::SaveHighScores()
{
	ifstream dat1("highscores.bin", ios_base::binary);
	if (!dat1)
	{

	}
	else
	{
		while (!dat1.eof())
		{
			int ID;
			dat1.read((char*)(&ID), sizeof(ID));
		
			int score;
			dat1.read((char*)(&score), sizeof(score));

			HighScore hs;
			hs.ID = ID;
			hs.score = score;

			scores.push_back(hs);
		}
	}
	dat1.close();
}

void SaveHighScores::loadScores()
{
	ifstream dat1("highscores.bin", ios_base::binary);
	if (!dat1)
	{

	}
	else
	{
		while (!dat1.eof())
		{
			int ID;
			dat1.read((char*)(&ID), sizeof(ID));

			int score;
			dat1.read((char*)(&score), sizeof(score));

			HighScore hs;
			hs.ID = ID;
			hs.score = score;

			scores.push_back(hs);
		}
	}
	dat1.close();
}



list<HighScore> SaveHighScores::getHighScoreList()
{
	return scores;
}

void SaveHighScores::addToList(int ID, int score)
{
	HighScore hs;
	hs.ID = ID;
	hs.score = score;

	removeIfFull();
}

void SaveHighScores::save()
{
	ofstream dat("highscores.bin", ios_base::binary);
	if (!dat)
	{
	}
	for (auto it = scores.rbegin(); it != scores.rend(); ++it)
	{
		int ID = it->ID;
		int score = it->score;

		dat.write((char*)(&ID), sizeof(ID));
		dat.write((char*)(&score), sizeof(score));
	}
	dat.close();
}

// Load add save
void SaveHighScores::lsa(int ID, int score)
{
	loadScores();
	addToList(ID, score);
	save();
}
