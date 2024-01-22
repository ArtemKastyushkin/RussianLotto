#if !defined CARD_H
#define CARD_H

#define ROWS 3
#define COLUMNS 9
#define CARD_NUMBERS_AMOUNT 15
#define ONES_MAX_AMOUNT 3
#define TWOS_MAX_AMOUNT 12

#include <iostream>
#include <map>
#include "cell.h"

class Card
{
private:
	int** _cells;
	std::map<int, Cell> _numbers;
	int _numbersRemaining;

	void initCard();
	void generateCard();
	void fillNumbers(bool isFilled = false);
public:
	Card();
	Card(int** cells);
	Card(const Card& card);
	Card(int cells[ROWS * COLUMNS], bool isFilled);
	~Card();

	void Check(int number);
	void Show(System::Windows::Forms::DataGridView^ cardBox);
	void Clear();
	bool IsFilled();
	int** GetCells();
};
#endif