#pragma once
#include <vector>

class Renderer {
public:
    void printBoard(const std::vector<std::vector<int>>& board);
    void printWelcome();
    void printWarning(const std::string& message);
};
