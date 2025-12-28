#include "Controller.hpp"
#include <iostream>

Controller::Controller(Board& b, Renderer& r, InputHandler& i, Validator& v)
    : board(b), renderer(r), input(i), validator(v) {}

bool Controller::createGame() const {
    try {
        SizeType sizeBoard;
        int selection;
        std::string fileName;

        while (true) {
            selection = input.inputBoardSize();
            if (validator.isCorrectNumber(1, 3, selection)) break;
            renderer.print("Invalid choice!");
        }

        switch (selection) {
            case 1:
                sizeBoard = FOUR;
                fileName = "sudoku1.txt";
                break;
            case 2:
                sizeBoard = SIX;
                fileName = "sudoku2.txt";
                break;
            case 3:
                sizeBoard = NINE;
                fileName = "sudoku3.txt";
                break;
            default: return false;
        }

        board.setBoardSize(sizeBoard);
        board.createBoard();

        if (!board.loadBoard("resource/" + fileName)) return false;

        return true;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void Controller::startGame() {
    loop = true;
}

void Controller::endGame() {
    loop = false;
}

void Controller::game() {
    if (!createGame()) {
        std::cerr << "Error when creating game!" << std::endl;
        return;
    }

    renderer.printWelcome();

    while (loop) {
        renderer.printBoard(board.getBoard());

        if (validator.isSudokuSolved(board.getBoard())) break;

        const player selection = input.inputPlayer();

        if (!validator.isCorrectNumber(1, board.getBoardSize(), selection.number) ||
            !validator.isCorrectNumber(1, board.getBoardSize(), selection.row) ||
            !validator.isCorrectNumber(1, board.getBoardSize(), selection.col)
            ) {
            renderer.print("Invalid number!");
            continue;
        }

        if (!validator.isCorrectPosition(selection.row, selection.col, board.getBoard(), selection.number)) {
            renderer.print("Invalid position!");
            continue;
        }

        board.changeBoard(selection.row, selection.col, selection.number);
    }

    if (!input.inputEndGame()) {
        board.deleteBoard();
        game();
    }
}
