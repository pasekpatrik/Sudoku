#pragma once

struct player {
    int PosX;
    int PosY;
    int number;
};

class InputHandler {
public:
    int inputBoardSize();
    bool inputEndGame();
    player inputPlayer();
};