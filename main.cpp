#include "controller/Controller.hpp"
#include "model/Board.hpp"
#include "controller/Validator.hpp"
#include "view/Renderer.hpp"
#include "view/InputHandler.hpp"
#include "view/InputHandlerRaw.hpp"
#include "view/TerminalRawMode.hpp"

#include <iostream>

int main(int argc, char* argv[]) {

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            std::cout
                << "Sudoku – terminalova verze hry\n\n"
                << "Pouziti:\n"
                << "  ./sudoku [--help]\n\n"
                << "Popis:\n"
                << "  Interaktivni Sudoku hra v textovem terminalu s ovladanim pomoci klavesnice.\n\n"
                << "Ovládání:\n"
                << "  - Sipky: pohyb kurzoru po herni desce\n"
                << "  - Cisla 1–9: vlozeni hodnoty do vybraneho pole\n"
                << "  - q: ukonceni hry\n\n"
                << "Prubeh hry:\n"
                << "  - Po spusteni vyber velikost desky (4x4, 6x6, 9x9)\n"
                << "  - Program automaticky kontroluje validitu tahu\n"
                << "  - Hra konci po vyplneni cele desky nebo stiskem 'q'\n";
            return 0;
        }
    }

    Board board;
    Validator validator;
    Renderer renderer;
    InputHandler inputHandler;
    InputHandlerRaw inputHandlerRaw;

    Controller controller(board, renderer, inputHandler, inputHandlerRaw, validator);

    if (!controller.createGame()) {
        std::cerr << "Error when creating game!" << std::endl;
        return 1;
    }

    set_raw(true);

    controller.startGame();
    controller.game();
    
    set_raw(false);

    return 0;
}