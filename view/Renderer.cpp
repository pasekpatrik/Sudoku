#include "Renderer.hpp"
#include <iostream>

void Renderer::render(Board board, int cursorRow, int cursorCol) {

    std::cout << "\033[2J\033[H";

    int size = board.getBoardSize();
    int blockRows = board.getBlockRow();
    int blockCols = board.getBlockCol();
    const auto& grid = board.getBoard();

    // Horní oddělovací čára
    auto printHorizontalLine = [&]() {
        for (int j = 0; j < size * 2 + blockCols * 2 + 1; j++) {
            std::cout << "-";
        }
        std::cout << "\n";
    };

    for (int r = 0; r < size; r++) {
        if (r % blockCols == 0) {
            printHorizontalLine();
        }

        for (int c = 0; c < size; c++) {

            if (c % blockRows == 0) {
                std::cout << "| ";
            }

            bool isCursor = (r == cursorRow && c == cursorCol);

            if (isCursor) {
                std::cout << "\033[43m"; // žluté pozadí
            }

            if (grid[r][c] != 0) {
                std::cout << grid[r][c] << " ";
            } else {
                std::cout << ". ";
            }

            if (isCursor) {
                std::cout << "\033[0m"; // reset barev
            }
        }

        std::cout << "|\n";
    }

    printHorizontalLine();
}

void Renderer::printWelcome() {
    std::cout << "Begin of Sudoku game!\n";
}

void Renderer::print(const std::string& message) {
    std::cout << message << "\n";
}
