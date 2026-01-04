#include "Controller.hpp"
#include <iostream>

Controller::Controller(Board& b, Renderer& r, InputHandler& menu, InputHandlerRaw& game, Validator& v)
    : board(b), renderer(r), menuInput(menu), gameInput(game), validator(v) {}

bool Controller::createGame() const {
    try {
        SizeType sizeBoard;
        int selection;
        std::string fileName;

        while (true) {
            selection = menuInput.inputBoardSize();
            if (validator.isCorrectNumber(1, 3, selection)) break;
            renderer.print("Invalid choice!");
        }

        switch (selection) {
            case 1: sizeBoard = FOUR; fileName = "sudoku1.txt"; break;
            case 2: sizeBoard = SIX;  fileName = "sudoku2.txt"; break;
            case 3: sizeBoard = NINE; fileName = "sudoku3.txt"; break;
            default: return false;
        }

        board.setBoardSize(sizeBoard);
        board.createBoard();

        return board.loadBoard("resource/" + fileName);

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

void Controller::moveCursor(Key key) {
    int size = board.getBoardSize();

    switch (key) {
        case Key::Up:    if (cursorRow > 0) cursorRow--; break;
        case Key::Down:  if (cursorRow < size - 1) cursorRow++; break;
        case Key::Left:  if (cursorCol > 0) cursorCol--; break;
        case Key::Right: if (cursorCol < size - 1) cursorCol++; break;
        default: break;
    }
}

void Controller::placeNumber(int number) {
    if (!validator.isCorrectNumber(1, board.getBoardSize(), number)) return;

    if (validator.isCorrectPosition(cursorRow, cursorCol, board, number)) {
        board.changeBoard(cursorRow, cursorCol, number);
    }
}

void Controller::game() {
    renderer.printWelcome();

    while (loop) {
        renderer.render(board, cursorRow, cursorCol);

        if (validator.isSudokuSolved(board.getBoard())) {
            loop = false;
            break;
            // TODO new game
        }

        InputEvent ev = gameInput.readKey();

        switch (ev.key) {
            case Key::Up:
            case Key::Down:
            case Key::Left:
            case Key::Right:
                moveCursor(ev.key);
                break;

            case Key::Number:
                placeNumber(ev.number);
                break;

            case Key::Quit:
                loop = false;
                break;

            default:
                break;
        }
    }
}
