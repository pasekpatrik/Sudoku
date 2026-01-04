#pragma once
#include "../model/SizeType.h"
#include <vector>
#include <string>

using namespace std;

class Board {
    vector<vector<int>> board;
    SizeType boardSize;
public:
    void createBoard();
    bool loadBoard(const std::string& filePath);
    bool changeBoard(int row, int col, int value);
    bool deleteBoard();
    vector<vector<int>> getBoard() const;
    SizeType getBoardSize() const;
    void setBoardSize(SizeType size);
    int getBlockRow() const;
    int getBlockCol() const;
};
