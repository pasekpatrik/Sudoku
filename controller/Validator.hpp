#pragma once
#include "../model/Board.hpp"

class Validator {
public:
    Validator();
    bool isCorrectNumber(int number);
    bool isCorrectPosition(int posX, int posY, const Board& board);
    bool isSudokuSolved(const Board& board);
};