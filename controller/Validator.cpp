#include "Validator.hpp"

bool Validator::isCorrectNumber(int from, int to, int number) {
    return number >= from && number <= to;
}

bool Validator::isCorrectPosition(int row, int col, Board board, int number) {
    const std::vector<std::vector<int>> boardVec = board.getBoard();

    if (boardVec[row - 1][col - 1] != 0) return false;

    for (const int &rowNumer : boardVec[row - 1]) {
        if (number == rowNumer) return false;
    }

    for (const vector<int>& rowBoard : boardVec) {
        if (rowBoard[col - 1] == number) return false;
    }

    const int row_size = board.getBlockRow();
    const int col_size = board.getBlockCol();

    const int square_row = (row / row_size) * row_size;
    const int square_col = (col / col_size) * col_size;

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (boardVec[square_row + i][square_col + j] == number) return false;
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
