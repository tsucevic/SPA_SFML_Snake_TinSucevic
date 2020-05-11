#pragma once
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

struct HighScore
{
	int ID;
	int score;
};

class SaveHighScores
{
private:
	list<HighScore> scores;
	
	void removeIfFull();
public:
	SaveHighScores();
	void loadScores();
	list<HighScore> getHighScoreList();

	void addToList(int ID, int score);
	void save();

	void lsa(int ID, int score);
};

