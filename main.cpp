#include "controller/Controller.hpp"
#include "controller/Controller.cpp"

#include "model/Board.hpp"
#include "model/Board.cpp"

#include "controller/Validator.hpp"
#include "controller/Validator.cpp"

#include "view/Renderer.hpp"
#include "view/Renderer.cpp"

#include "view/InputHandler.hpp"
#include "view/InputHandler.cpp"

int main() {
    Board board;
    Validator validator;
    Renderer renderer;
    InputHandler inputHandler;

    Controller controller(board, renderer, inputHandler, validator);

    controller.startGame();
    controller.game();

    return 0;
}