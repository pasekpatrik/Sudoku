#include "Validator.hpp"

bool Validator::isCorrectNumber(int from, int to, int number) {
    return number >= from && number <= to;
}

bool Validator::isCorrectPosition(int posX, int posY, const vector<vector<int>>& board) {
    return true;
}

bool Validator::isSudokuSolved(const std::vector<std::vector<int>>& board) {
   for (const std::vector<int>& row : board) {
       for (const int one : row) {
           if (one == 0) return false;
       }
   }

    return true;
}
