#include "cell.h"

Cell::Cell() : _position(), _isMarked(false) {}

Cell::Cell(Position position) : _position(position), _isMarked(false) {}

Cell::Cell(const Cell& cell) : _position(cell._position), _isMarked(cell._isMarked) {}

Position Cell::GetPosition() { return _position; }

bool Cell::IsMarked() { return _isMarked; }

void Cell::Mark() { _isMarked = true; }

void Cell::Clear() { _isMarked = false; }