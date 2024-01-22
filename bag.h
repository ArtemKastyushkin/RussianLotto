#if !defined BAG_H
#define BAG_H

#define KEGS_AMOUNT 90

#include <vector>

class Bag
{
private:
	std::vector<int> _kegs = std::vector<int>(KEGS_AMOUNT);

	void fill();
public:
	Bag();
	int Get();
	void Show();
	void Refill();

	int operator-- ();
};

#endif