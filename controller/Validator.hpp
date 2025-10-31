#pragma once
#include "../model/Board.hpp"

class Validator {
public:
    bool isCorrectNumber(int from, int to, int number);
    bool isCorrectPosition(int posX, int posY, const vector<vector<int>> &board);
    bool isSudokuSolved(const vector<vector<int>> &board);
};