#pragma once
#include <string>
#include "Board.hpp"

class Renderer {
public:
    void render(Board board, int cursorRow, int cursorCol);
    void printWelcome();
    void print(const std::string& message);
};
