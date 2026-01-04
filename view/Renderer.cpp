#include "Renderer.hpp"
#include <iostream>
#include <vector>

void Renderer::printBoard(Board board) {
   for (int i = 0; i < board.getBoardSize(); i++) {
       if (i % board.getBlockCol() == 0) {
           for (int j = 0; j < board.getBoardSize() * 2 + board.getBlockCol() * 2 + 1; j++) {
               std::cout << "-";
           }
           std::cout << std::endl;
       }

       for (int j = 0; j < board.getBoard()[i].size(); j++) {
           if (j % board.getBlockRow() == 0) {
               std::cout<< "| ";
           }

           if (board.getBoard()[i][j] != 0) {
               std::cout << board.getBoard()[i][j] << " ";
           } else {
               std::cout << ". ";
           }
       }

       std::cout << "|" << std::endl;
   }

    for (int j = 0; j < board.getBoardSize() * 2 + board.getBlockCol() * 2 + 1; j++) {
        std::cout << "-";
    }

    std::cout << std::endl;
}

void Renderer::printWelcome() {
    std::cout << "Begin of Sudoku game!" << std::endl;
}

void Renderer::print(const std::string& message) {
    std::cout << message << std::endl;
}
