#include "game.h"
#include "computer.h"
#include "human.h"
#include <iostream>

using namespace std;

void Game::fillUnplayedCards()
{
	_unplayedCards.clear();

	for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
	{
		if (!_cards[i]->IsFilled())
			_unplayedCards.push_back(i);
	}
}

Game::Game(ShortCardObject cards[MAX_CARDS_AMOUNT], std::string humanName, int humanBalance, int bank, int roundsCount)
{
	for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
		_cards.push_back(new Card(cards[i].Nums, cards[i].IsCardFilled));

	fillUnplayedCards();

	_players.push_back(new Human(humanName, this, humanBalance));
	_players.push_back(new Computer("PC", this));

	_bank = bank;
	_roundsCount = roundsCount;
	_winner = nullptr;

	_bag.Refill();
}

Game::Game(const Game& game)
{
	for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
		_cards.push_back(new Card{ *game._cards[i] });

	for (int i = 0; i < game._unplayedCards.size(); i++)
		_unplayedCards.push_back(game._unplayedCards[i]);

	for (int i = 0; i < game._players.size(); i++)
		_players.push_back(game._players[i]);

	_bank = game._bank;
	_roundsCount = game._roundsCount;
	_winner = nullptr;

	_bag.Refill();
}

Game::Game(string humanName)
{
	for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
		_cards.push_back(new Card());

	_players.push_back(new Human(humanName, this, START_BALANCE));
	_players.push_back(new Computer("PC", this));

	_bank = 0;

	fillUnplayedCards();

	_winner = nullptr;

	_roundsCount = 1;
}

void Game::GiveCards()
{
	for (int i = 0; i < PLAYERS_AMOUNT; i++)
	{
		int unplayedPosition = rand() % _unplayedCards.size();
		int cardPosition = _unplayedCards[unplayedPosition];

		if (_players[i]->TakeCard(_cards[cardPosition]))
		{
			_unplayedCards.erase(_unplayedCards.begin() + unplayedPosition);
			_bank += CARD_COST;
		}
	}
}

void Game::ReportVictory(Player* player)
{
	player->TakePrize(_bank);

	_bank = 0;

	_winner = player;

	_roundsCount++;
}

void Game::Refresh()
{
	for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
		_cards[i]->Clear();

	fillUnplayedCards();
}

int Game::GetBank() { return _bank; }

int Game::GetUserBalance() { return _players[0]->GetUserBalance(); }

std::string Game::GetUserName() { return _players[0]->GetName(); }

int Game::GetKeg() 
{
	int keg = _bag.Get();

	for (int i = 0; i < PLAYERS_AMOUNT; i++)
	{
		_players[i]->CheckNumber(keg);
		_players[i]->CheckCard();
	}

	return keg; 
}

void Game::ShowPlayersCard(System::Windows::Forms::DataGridView^ humanCardBox, System::Windows::Forms::DataGridView^ computerCardBox)
{
	_players[0]->ShowCard(humanCardBox);
	_players[1]->ShowCard(computerCardBox);
}

bool Game::HasWinner() { return _winner != nullptr; }

void Game::NextRound()
{
	if (_roundsCount == MAX_ROUND_AMOUNT)
		Refresh();

	_bag.Refill();
	GiveCards();
	_winner = nullptr;
}

int Game::GetRoundsCount() { return _roundsCount; }

std::string Game::GetWinnerName() { return _winner->GetName(); }

vector<Card*> Game::GetCards() { return _cards; }