#if !defined SHORT_CARD_OBJECT_H
#define SHORT_CARD_OBJECT_H

#include "card.h"

class ShortCardObject
{
public:
	int Nums[ROWS * COLUMNS];
	bool IsCardFilled;

	ShortCardObject() {}

	ShortCardObject(int nums[ROWS * COLUMNS], bool isCardFilled)
	{
		for (int i = 0; i < ROWS * COLUMNS; i++)
			Nums[i] = nums[i];

		IsCardFilled = isCardFilled;
	}
};

#endif#