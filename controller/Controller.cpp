#include "Controller.hpp"
#include <iostream>

Controller::Controller(Board& b, Renderer& r, InputHandler& i, Validator& v)
    : board(b), renderer(r), input(i), validator(v) {}

bool Controller::createGame() const {
    try {
        SizeType sizeBoard;
        const int selection = input.inputBoardSize();

        if (!validator.isCorrectNumber(1, 3, selection)) return false;

        switch (selection) {
            case 1: sizeBoard = FOUR; break;
            case 2: sizeBoard = SIX; break;
            case 3: sizeBoard = NINE; break;
            default: return false;
        }

        board.setBoardSize(sizeBoard);
        board.createBoard();
        // TODO
        // board.loadBoard(name);
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

        if (!validator.isCorrectNumber(1, board.getBoardSize(), selection.number)) {
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
