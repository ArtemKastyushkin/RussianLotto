#if !defined RECORD_H
#define RECORD_H

#include <iostream>

class Record
{
private:
	std::string _name;
	int _score;
	int _roundsPassedAmount;
public:
	Record(std::string name, int score, int roundsPassedAmount);

	std::string GetName();
	int GetScore();
	int GetRoundsPassedAmount();
};

#endif#