#include <string>
#include <vector>
#include <fstream>
#include "SizeType.h"
#include "Board.hpp"

#include <cstring>
#include <filesystem>
#include <iostream>

void Board::createBoard() {
    for (int i = 0; i < boardSize; i++) {
        vector<int> vec;

        for (int j = 0; j < boardSize; j++) {
            vec.push_back(0);
        }

        board.push_back(vec);
    }
}

bool Board::changeBoard(const int row, const int col, const int value) {
    board[row][col] = value;
    return true;
}

bool Board::loadBoard(const std::string &filePath) {
    try {
        ifstream file("../" + filePath);

        if (!file.is_open()) {
            std::cerr << "File is not open!" << std::endl;
            std::cout << "Reason: " << std::strerror(errno) << std::endl;
            std::cout << "Trying to open: " << filesystem::absolute(filePath) << std::endl;

            return false;
        }

        int Row, Col, value;
        while (file >> Row >> Col >> value) {
            changeBoard(Row, Col, value);
        }

        file.close();
        return true;
    } catch (exception const &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool Board::deleteBoard() {
    board.clear();
    return true;
}

std::vector<std::vector<int>> Board::getBoard() const {
    return board;
}

SizeType Board::getBoardSize() const {
    return boardSize;
}

void Board::setBoardSize(const SizeType size) {
    boardSize = size;
}

int Board::getBlockRow() const {
    switch (boardSize) {
        case 4:
            return 2;
        case 6:
            return 2;
        case 9:
            return 3;
        default: throw std::runtime_error("Unsupported board size");
    }
}
int Board::getBlockCol() const {
    switch (boardSize) {
        case 4:
            return 2;
        case 6:
            return 3;
        case 9:
            return 3;
        default: throw std::runtime_error("Unsupported board size");
    }
}