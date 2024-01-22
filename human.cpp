#include "human.h"
#include "my_exception.h"

Human::Human(std::string name, Game* game, int balance) : Player(name, game)
{
	if (balance < 0)
		throw MyException("The balance is under zero!", ExceptionType::InvalidValue);

	_balance = balance;
}

bool Human::TakeCard(Card* card)
{
	if (_balance - CARD_COST < 0)
		return false;

	_card = card;

	_balance -= CARD_COST;

	return true;
}

void Human::TakePrize(int prize) { _balance += prize; }

int Human::GetUserBalance() { return _balance; }