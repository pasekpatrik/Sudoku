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
    bool changeBoard(int posX, int posY, int value);
    bool deleteBoard();
    vector<vector<int>> getBoard();
    SizeType getBoardSize();
    void setBoardSize(SizeType size);
};
