#include "../model/SizeType.h"

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

    public:
        Controller(Board& b, Renderer& r, InputHandler& i, Validator& v)
            : board(b), renderer(r), input(i), validator(v) {}

        bool createGame() {
            try {
                const SizeType sizeBoard = input.inputBoardSize();
                board.createBoard(sizeBoard);
                // board.loadBoard("name.txt");
                return true;
            } catch (std::exception& e) {
                return false;
            }
        }

        void startGame() {
            loop = true;
        }

        void endGame() {
            loop = false;
        }

        void game() {
            if (!createGame()) return;

            while (loop) {

            }
        }
};
