#if !defined GAME_H
#define GAME_H

#define MAX_CARDS_AMOUNT 24
#define PLAYERS_AMOUNT 2
#define CARD_COST 10
#define START_BALANCE 100
#define MAX_ROUND_AMOUNT 13

#include "bag.h"
#include "card.h"
#include "player.h"
#include <vector>
#include "ShortCardObject.h"

class Player;

class Game
{
private:
	Bag _bag;
	std::vector<Card*> _cards;
	std::vector<int> _unplayedCards;
	std::vector<Player*> _players;
	Player* _winner;
	int _bank;
	int _roundsCount;

	void fillUnplayedCards();
public:
	Game(ShortCardObject cards[MAX_CARDS_AMOUNT], std::string humanName, int humanBalance, int bank, int roundsCount);
	Game(const Game& game);
	Game(std::string humanName);

	void GiveCards();
	void ReportVictory(Player* player);
	void Refresh();
	void ShowPlayersCard(System::Windows::Forms::DataGridView^ humanCardBox, System::Windows::Forms::DataGridView^ computerCardBox);
	int GetBank();
	int GetUserBalance();
	std::string GetUserName();
	int GetKeg();
	bool HasWinner();
	void NextRound();
	int GetRoundsCount();
	std::string GetWinnerName();
	std::vector<Card*> GetCards();
};

#endif#