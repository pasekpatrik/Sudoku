#pragma once
#include "../model/Board.hpp"
#include "../view/Renderer.hpp"
#include "../view/InputHandler.hpp"
#include "Validator.hpp"

class Controller {
    bool loop = false;
    Board& board;
    Renderer& renderer;
    InputHandler& input;
    Validator& validator;
    bool createGame() const;
public:
    Controller(Board& b, Renderer& r, InputHandler& i, Validator& v);
    void startGame();
    void endGame();
    void game() const;
};