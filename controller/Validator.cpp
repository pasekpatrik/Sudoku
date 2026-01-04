#include "Validator.hpp"

bool Validator::isCorrectNumber(int from, int to, int number) {
    return number >= from && number <= to;
}

bool Validator::isCorrectPosition(int row, int col, const Board& board, int number) {
    const auto& boardVec = board.getBoard();

    int size = board.getBoardSize();
    if (row < 0 || row >= size || col < 0 || col >= size) return false;

    if (boardVec[row][col] != 0) return false;

    for (int c = 0; c < size; c++) {
        if (boardVec[row][c] == number) return false;
    }

    for (int r = 0; r < size; r++) {
        if (boardVec[r][col] == number) return false;
    }

    int blockRows = board.getBlockRow();
    int blockCols = board.getBlockCol();

    int startRow = (row / blockRows) * blockRows;
    int startCol = (col / blockCols) * blockCols;

    for (int r = 0; r < blockRows; r++) {
        for (int c = 0; c < blockCols; c++) {
            if (boardVec[startRow + r][startCol + c] == number) return false;
        }
    }

    return true;
}


bool Validator::isSudokuSolved(const std::vector<std::vector<int>>& board) {
   for (const std::vector<int>& row : board) {
       for (const int& one : row) {
           if (one == 0) return false;
       }
   }

    return true;
}
