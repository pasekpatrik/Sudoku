#include "Renderer.hpp"
#include <iostream>
#include <vector>

void Renderer::printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto & i : board) {
        for (int j : i) {
            std::string result = (j == 0) ? "." : std::to_string(j);
            std::cout << "|" << result << "|";
        }

        std::cout << "\n";
    }
}

void Renderer::printWelcome() {
    std::cout << "Begin of Sudoku game!" << std::endl;
}

void Renderer::printWarning(const std::string& message) {
    std::cout << message << std::endl;
}
