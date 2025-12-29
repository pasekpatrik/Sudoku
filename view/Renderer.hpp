#pragma once
#include <string>
#include "Board.hpp"

class Renderer {
public:
    void printBoard(Board board);
    void printWelcome();
    void print(const std::string& message);
};
