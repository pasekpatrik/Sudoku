#include "Renderer.hpp"
#include <iostream>

void Renderer::render(const Board& board, int cursorRow, int cursorCol) {

    std::cout << "\033[H\033[J";

    int size = board.getBoardSize();
    int blockRows = board.getBlockRow();
    int blockCols = board.getBlockCol();
    const auto& grid = board.getBoard();

    auto printHorizontalLine = [&]() {
        int lineLength = size * 2 + (size / blockCols) * 2 + 1;
        for (int j = 0; j < lineLength; j++) {
            std::cout << "-";
        }
        std::cout << "\r\n";
    };

    for (int r = 0; r < size; r++) {

        if (r % blockRows == 0)
            printHorizontalLine();

        for (int c = 0; c < size; c++) {

            if (c % blockCols == 0)
                std::cout << "| ";

            bool isCursor = (r == cursorRow && c == cursorCol);

            if (isCursor)
                std::cout << "\033[43m";

            if (grid[r][c] != 0)
                std::cout << grid[r][c] << " ";
            else
                std::cout << ". ";

            if (isCursor)
                std::cout << "\033[0m";
        }

        std::cout << "|\r\n";
    }

    printHorizontalLine();

    std::cout << std::flush;
}

void Renderer::printWelcome() {
    std::cout << "Begin of Sudoku game!\r\n";
    std::cout << std::flush;
}

void Renderer::print(const std::string& message) {
    std::cout << message << "\r\n";
    std::cout << std::flush;
}
