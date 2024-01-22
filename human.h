#if !defined HUMAN_H
#define HUMAN_H

#include "player.h"
#include "game.h"

class Human : public Player
{
private:
	int _balance;
public:
	Human(std::string name, Game* game, int balance = START_BALANCE);

	bool TakeCard(Card* card) override;
	void TakePrize(int prize) override;
	int GetUserBalance() override;
};

#endif#