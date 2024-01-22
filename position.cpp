#include "position.h"

Position::Position() : _row(0), _column(0) {}

Position::Position(int row, int column) : _row(row), _column(column) {}

Position::Position(const Position& position) : _row(position._row), _column(position._column) {}

int Position::GetRow() { return _row; }

int Position::GetColumn() { return _column; }