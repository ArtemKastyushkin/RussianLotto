#include "card.h"
#include <cstddef>
#include "my_exception.h"

void Card::initCard()
{
	_cells = new int* [ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		_cells[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
			_cells[i][j] = 0;
	}
}

void Card::generateCard()
{
	int sumOfOnes = 0, sumOfTwos = 0;

	int cardMap[COLUMNS];

	for (int i = 0; i < COLUMNS; i++)
	{
		cardMap[i] = (1 + sumOfOnes / ONES_MAX_AMOUNT) + rand() % (2 - sumOfOnes / ONES_MAX_AMOUNT - sumOfTwos / TWOS_MAX_AMOUNT);

		if (cardMap[i] == 1)
			sumOfOnes += cardMap[i];
		else
			sumOfTwos += cardMap[i];
	}

	int i = rand() % ROWS;

	for (int j = 0; j < COLUMNS; j++)
	{
		for (int k = 0; k < cardMap[j]; k++)
		{
			int startOffset = j == 0 ? 1 : 0;
			int endOffset = j == COLUMNS - 1 ? 1 : 0;

			int generatedNumber = 0;

			do
			{
				generatedNumber = j * (COLUMNS + 1) + startOffset + rand() % ((COLUMNS + 1) - startOffset + endOffset);
			} while (_numbers.count(generatedNumber));

			_cells[i][j] = generatedNumber;
			_numbers[generatedNumber] = Cell(Position(i, j));

			i++;
			if (i == ROWS)
				i = 0;
		}
	}
}

void Card::fillNumbers(bool isFilled)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (_cells[i][j] != 0)
			{
				if (_cells[i][j] < 1 || _cells[i][j] > COLUMNS * 10)
					throw MyException("Number in card is not in range {1, ..., 90}", ExceptionType::OutOfRange);

				_numbers[_cells[i][j]] = Cell(Position(i, j));

				if (isFilled)
					_numbers[_cells[i][j]].Mark();
			}
		}
	}

	if (_numbers.size() > CARD_NUMBERS_AMOUNT)
		throw MyException("Too many numbers on the card!", ExceptionType::Overflow);
}

Card::Card()
{
	initCard();

	generateCard();

	_numbersRemaining = CARD_NUMBERS_AMOUNT;
}

Card::Card(int** cells)
{
	if (cells != NULL)
	{
		_cells = cells;
		fillNumbers();
	}
	else
	{
		initCard();
		generateCard();
	}

	_numbersRemaining = CARD_NUMBERS_AMOUNT;
}

Card::Card(const Card& card)
{
	_cells = new int* [ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		_cells[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
			_cells[i][j] = card._cells[i][j];
	}

	_numbers = card._numbers;

	_numbersRemaining = card._numbersRemaining;
}

Card::Card(int cells[ROWS * COLUMNS], bool isFilled)
{
	int k = 0;

	_cells = new int* [ROWS];

	for (int i = 0; i < ROWS; i++)
	{
		_cells[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
		{
			_cells[i][j] = cells[k];
			k++;
		}
	}

	fillNumbers(isFilled);

	_numbersRemaining = isFilled ? 0 : CARD_NUMBERS_AMOUNT;
}

Card::~Card()
{
	if (_cells != NULL)
	{
		for (int i = 0; i < ROWS; i++)
			delete[] _cells[i];

		delete[] _cells;
	}
}

void Card::Check(int number)
{
	if (_numbers.count(number))
	{
		_numbers[number].Mark();

		_numbersRemaining--;
	}
}

void Card::Show(System::Windows::Forms::DataGridView^ cardBox)
{
	for (int i = 0; i < cardBox->RowCount; i++)
	{
		for (int j = 0; j < cardBox->ColumnCount; j++)
		{
			int cellNum = _cells[i][j];

			if (cellNum != 0)
			{
				if (_numbers.count(cellNum) && _numbers[cellNum].IsMarked())
					cardBox->Rows[i]->Cells[j]->Value = "x";
				else
					cardBox->Rows[i]->Cells[j]->Value = cellNum;
			}
		}
	}
}

void Card::Clear()
{
	_numbers.clear();

	fillNumbers();

	_numbersRemaining = CARD_NUMBERS_AMOUNT;
}

bool Card::IsFilled() { return _numbersRemaining == 0; }

int** Card::GetCells() { return _cells; }