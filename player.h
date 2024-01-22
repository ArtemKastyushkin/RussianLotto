#if !defined PLAYER_H
#define PLAYER_H

#include "card.h"
#include "game.h"

class Game;

class Player
{
protected:
	std::string _name;
	Card* _card;
	Game* _game;
public:
	Player(std::string name, Game* game);

	std::string GetName();
	void ShowCard(System::Windows::Forms::DataGridView^ cardBox);
	void CheckCard();
	void CheckNumber(int number);
	virtual bool TakeCard(Card* card);
	virtual void TakePrize(int prize) { };
	virtual int GetUserBalance() { return 0; };
};

#endif#