#pragma once
#include "../model/Board.hpp"

class Validator {
public:
    bool isCorrectNumber(int from, int to, int number);
    bool isCorrectPosition(int row, int col, Board board, int number);
    bool isSudokuSolved(const vector<vector<int>> &board);
};