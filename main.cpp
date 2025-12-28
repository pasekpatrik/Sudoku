#include "controller/Controller.hpp"

#include "model/Board.hpp"

#include "controller/Validator.hpp"

#include "view/Renderer.hpp"

#include "view/InputHandler.hpp"

#include <iostream>

int main(int argc, char* argv[]) {

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            std::cout << "Sudoku hra v textovem rezimu\n\n"
                      << "Pouziti:\n"
                      << "  ./sudoku [--help]\n\n"
                      << "Ovládání:\n"
                      << "  - Po spusteni vyber velikost desky (4x4, 6x6, 9x9)\n"
                      << "  - Tahy zadavej jako: cislo radek sloupec\n"
                      << "  - Program kontroluje validitu tahu\n"
                      << "  - Hra konci po vyreseni sudoku nebo volbou ukonceni\n";
            return 0;
        }
    }

    Board board;
    Validator validator;
    Renderer renderer;
    InputHandler inputHandler;

    Controller controller(board, renderer, inputHandler, validator);

    controller.startGame();
    controller.game();

    return 0;
}