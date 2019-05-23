#include "testharness.h"
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowFlag[9][9];
        int columnFlag[9][9];
        int squareFlag[9][9];

        memset(rowFlag, 0, sizeof(rowFlag));
        memset(columnFlag, 0, sizeof(columnFlag));
        memset(squareFlag, 0, sizeof(squareFlag));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';

                if (++rowFlag[i][num] > 1) return false;
                if (++columnFlag[j][num] > 1) return false;

                int k = i / 3 + (j / 3) * 3;
                if (++squareFlag[k][num] > 1) return false;
            }
        }

        return true;
    }
};

TEST(Solution, test) {
    vector<char> tmp(9, '.');
    vector<vector<char> > board(9, tmp);

    for (int i = 1; i < 9; i++)
        board[0][i] = '0' + 9 - i;

    for (int i = 1; i < 9; i++)
        board[i][0] = '0' + i + 1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
    std::cout << (isValidSudoku(board) ? "true" : "false") << "\n";
}
