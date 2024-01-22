#if !defined CELL_H
#define CELL_H

#include "position.h"

class Cell
{
private:
	Position _position;
	bool _isMarked;
public:
	Cell();
	Cell(Position position);
	Cell(const Cell& cell);

	Position GetPosition();
	bool IsMarked();
	void Mark();
	void Clear();
};

#endif