#pragma once
#include "../model/SizeType.h"
#include <vector>
#include <string>

class Board {
private:
    std::vector<std::vector<int>> board;

public:
    Board();
    void createBoard(SizeType size);
    bool loadBoard(const std::string& fileName);
    bool changeBoard(int posX, int posY, int value);
    bool deleteBoard();
};
