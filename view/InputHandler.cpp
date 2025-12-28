#include "InputHandler.hpp"

#include <iostream>
using namespace std;

int InputHandler::inputBoardSize() {
    int selection;

    cout << "Select the size of the board(1. 4x4, 2. 6x6, 3. 9x9): " << endl;
    cin >> selection;

    return selection;
}

player InputHandler::inputPlayer() {
    player input{};

    cout << "Select the Row, Col, Number: " << endl;
    cin >> input.row >> input.col >> input.number;

    return input;
}

bool InputHandler::inputEndGame() {
    std::string result;

    cout << "Do you want end of the game? (y/n): " << endl;
    cin >> result;

    return (result == "y");
}
