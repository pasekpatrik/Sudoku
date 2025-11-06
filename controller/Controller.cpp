#include "Controller.hpp"
#include <iostream>

Controller::Controller(Board& b, Renderer& r, InputHandler& i, Validator& v)
    : board(b), renderer(r), input(i), validator(v) {}

bool Controller::createGame() const {
    try {
        SizeType sizeBoard;
        const int selection = input.inputBoardSize();
        std::string fileName;

        if (!validator.isCorrectNumber(1, 3, selection)) return false;

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
        return false;
    }
}

void Controller::startGame() {
    loop = true;
}

void Controller::endGame() {
    loop = false;
}

void Controller::game() const {
    if (!createGame()) return;

    renderer.printWelcome();

    while (loop) {
        renderer.printBoard(board.getBoard());

        if (validator.isSudokuSolved(board.getBoard())) break;

        const player selection = input.inputPlayer();

        if (!validator.isCorrectNumber(1, board.getBoardSize(), selection.number) |
            !validator.isCorrectNumber(1, board.getBoardSize(), selection.PosX) |
            !validator.isCorrectNumber(1, board.getBoardSize(), selection.PosY)
            ) {
            renderer.printWarning("Invalid number!");
            continue;
        }

        if (!validator.isCorrectPosition(selection.PosX, selection.PosY, board.getBoard())) {
            renderer.printWarning("Invalid position!");
            continue;
        }

        board.changeBoard(selection.PosX, selection.PosY, selection.number);
    }

    if (!input.inputEndGame()) {
        board.deleteBoard();
        game();
    }
}
