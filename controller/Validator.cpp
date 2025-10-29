#include <vector>

using namespace std;

class Validator {
    public:
        bool isCorrectNumber(int from, int to, int number) {
            return true;
        }

        bool isCorrectPosition(int PosX, int PosY, int number) {
            return true;
        }

        bool isSudokuSolved(const vector<vector<int>>& board) {
            return false;
        }
};