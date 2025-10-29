#include "../model/SizeType.h"

class InputHandler {
    public:
        InputHandler() = default;
        SizeType inputBoardSize() {
            return SIX;
        }

        // TODO struct x, y, number
        void inputPlayer() {

        }

        bool inputEndGame() {
            return false;
        }
};
