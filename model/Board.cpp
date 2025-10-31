#include <string>
#include <vector>
#include "SizeType.h"
#include "Board.hpp"

using namespace std;

void Board::createBoard() {
    for (int i = 0; i < boardSize; i++) {
        vector<int> vec;

        for (int j = 0; j < boardSize; j++) {
            vec.push_back(0);
        }

        board.push_back(vec);
    }
}

bool Board::changeBoard(const int posX, const int posY, const int value) {
    board[posX - 1][posY - 1] = value;
    return true;
}

bool Board::loadBoard(const std::string &fileName) {
    return true;
}

bool Board::deleteBoard() {
    board.clear();
    return true;
}

std::vector<std::vector<int>> Board::getBoard() {
    return board;
}

SizeType Board::getBoardSize() {
    return boardSize;
}

void Board::setBoardSize(const SizeType size) {
    boardSize = size;
}