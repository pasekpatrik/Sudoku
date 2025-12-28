#pragma once
#include <vector>
#include <string>

class Renderer {
public:
    void printBoard(const std::vector<std::vector<int>>& board);
    void printWelcome();
    void print(const std::string& message);
};
