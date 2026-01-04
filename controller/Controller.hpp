#pragma once
#include "../model/Board.hpp"
#include "../view/Renderer.hpp"
#include "../view/InputHandler.hpp"
#include "../view/InputHandlerRaw.hpp"
#include "Validator.hpp"

class Controller {
    bool loop = false;

    Board& board;
    Renderer& renderer;

    InputHandler& menuInput;
    InputHandlerRaw& gameInput;

    Validator& validator;

    int cursorRow = 0;
    int cursorCol = 0;


    void moveCursor(Key key);
    void placeNumber(int number);

public:
    Controller(Board& b, Renderer& r, InputHandler& menu, InputHandlerRaw& game, Validator& v);

    bool createGame() const;
    void startGame();
    void endGame();
    void game();
};
