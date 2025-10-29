#include <string>
#include <vector>
#include "SizeType.h"
using namespace std;

class Board {
    vector<vector<int>> board;

    public:
        void createBoard(const SizeType size) {
            for (int i = 0; i < size; i++) {
                vector<int> vec;

                for (int j = 0; j < size; j++) {
                    vec.push_back(0);
                }

                board.push_back(vec);
            }
        }

        bool loadBoard(const std::string& fileName) {
            return true;
        }

        bool changeBoard(int PosX, int PosY, int number) {
            return true;
        }

        bool deleteBoard() {
            return true;
        }
};
