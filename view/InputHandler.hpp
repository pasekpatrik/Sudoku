#pragma once

struct player {
    int row;
    int col;
    int number;
};

class InputHandler {
public:
    int inputBoardSize();
    bool inputEndGame();
    player inputPlayer();
};