#include "bag.h"
#include <iostream>

void Bag::fill()
{
	for (int i = 0; i < _kegs.size(); i++)
		_kegs[i] = i + 1;
}

Bag::Bag() { fill(); }

int Bag::Get()
{
	int randomIndex = rand() % _kegs.size();
	int randomKeg = _kegs[randomIndex];

	_kegs.erase(_kegs.cbegin() + randomIndex);

	return randomKeg;
}

void Bag::Show()
{
	for (int i = 0; i < _kegs.size(); i++)
		std::cout << _kegs[i] << " ";

	std::cout << std::endl;
}

void Bag::Refill()
{
	_kegs.clear();

	_kegs = std::vector<int>(KEGS_AMOUNT);

	fill();
}

int Bag::operator--()
{
	return Get();
}