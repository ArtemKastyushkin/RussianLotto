#if !defined COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer : public Player
{
public:
	Computer(std::string name, Game* game);
};

#endif#