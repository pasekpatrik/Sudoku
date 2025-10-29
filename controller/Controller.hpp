#pragma once
#include "../model/Board.hpp"
#include "../view/Renderer.hpp"
#include "../view/InputHandler.hpp"
#include "Validator.hpp"

class Controller {
private:
    bool loop = false;
    Board& board;
    Renderer& renderer;
    InputHandler& input;
    Validator& validator;

public:
    Controller(Board& b, Renderer& r, InputHandler& i, Validator& v);
    bool createGame();
    void startGame();
    void endGame();
    void game();
};