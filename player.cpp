#include "player.h"
#include "my_exception.h"

Player::Player(std::string name, Game* game) : _name(name), _game(game) { }

std::string Player::GetName() { return _name; }

void Player::ShowCard(System::Windows::Forms::DataGridView^ cardBox)
{
	if (_card == NULL)
		throw MyException("Card is not initialized!", ExceptionType::NullPtr);

	_card->Show(cardBox);
}

void Player::CheckCard()
{
	if (_card->IsFilled())
		_game->ReportVictory(this);
}

void Player::CheckNumber(int number) { _card->Check(number); }

bool Player::TakeCard(Card* card)
{
	_card = card;

	return true;
}