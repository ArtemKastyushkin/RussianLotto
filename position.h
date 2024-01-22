#if !defined POSITION_H
#define POSITION_H

class Position
{
private:
	int _row;
	int _column;
public:
	Position();
	Position(int row, int column);
	Position(const Position& position);

	int GetRow();
	int GetColumn();
};

#endif