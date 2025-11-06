#include <string>
#include <vector>
#include <fstream>
#include "SizeType.h"
#include "Board.hpp"
#include <filesystem>

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

bool Board::loadBoard(const std::string &filePath) {
    try {
        ifstream file(filePath);

        if (!file.is_open()) return false;

        int PosX, PosY, value;
        while (file >> PosX >> PosY >> value) {
            changeBoard(PosX, PosY, value);
        }

        file.close();
        return true;
    } catch (exception &e) {
        return false;
    }
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