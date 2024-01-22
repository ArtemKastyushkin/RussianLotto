#include "record.h"

Record::Record(std::string name, int score, int roundsPassedAmount) : _name{ name }, _score{ score }, _roundsPassedAmount{ roundsPassedAmount} { }

std::string Record::GetName() { return _name; }
int Record::GetScore() { return _score; }
int Record::GetRoundsPassedAmount() { return _roundsPassedAmount; }