#include "Validator.hpp"

bool Validator::isCorrectNumber(int from, int to, int number) {
    return number >= from && number <= to;
}

bool Validator::isCorrectPosition(int row, int col, const vector<vector<int>>& board, int number) {
    if (board[row - 1][col - 1] != 0) return false;

    for (const int &rowNumer : board[row - 1]) {
        if (number == rowNumer) return false;
    }

    for (const vector<int>& rowBoard : board) {
        if (rowBoard[col - 1] == number) return false;
    }

    const int square_row = (row / 3) * 3;
    const int square_col = (col / 3) * 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[square_row + i][square_col + j] == number) return false;
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
