#pragma once
#include "../model/SizeType.h"

class InputHandler {
public:
    InputHandler();
    SizeType inputBoardSize();
    bool inputEndGame();
    void inputPlayer();
};