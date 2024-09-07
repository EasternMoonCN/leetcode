//
// Created by EasternMoon on 2024/6/21.
//

/*
 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）


注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
 */
#include "utils/head.h"

class Solution {
public:
/*    bool checkRow(vector<vector<char> > &board, char digit, int row, int col, int rows) {
        for (int i = 0; i < rows; ++i) {
            if (i != row && digit == board[i][col]) {
                return false;
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char> > &board, char digit, int row, int col, int cols) {
        for (int j = 0; j < cols; ++j) {
            if (j != col && digit == board[row][j]) {
                return false;
            }
        }
        return true;
    }

    bool checkSquare(vector<vector<char> > &board, char digit, int i, int j) {
        int rowStart = 3 * (i / 3), colStart = 3*(j / 3);
        for (int row = rowStart;  row< rowStart + 3; ++row) {
            for (int col = colStart; col < colStart + 3; ++col) {
                if (row != i && col != j && digit == board[row][col]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isdigit(board[i][j])) {
                    if (!(checkRow(board, board[i][j], i, j, rows) && checkCol(board, board[i][j], i, j, cols) && checkSquare(board, board[i][j], i, j))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }*/

    /*bool isValidSudoku(vector<vector<char> > &board) {
        // 每行1-9元素个数
        int rows[9][9] = {0};
        // 每列1-9元素个数
        int cols[9][9] = {0};
        // 每小正方格1-9元素个数
        int square[3][3][9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (isdigit(c)) {
                    // 行，列，正方格元素个数出现过
                    if (rows[i][c - '1']++ > 0 || cols[j][c - '1']++ > 0 || square[i/3][j/3][c - '1']++ > 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }*/

    bool isValidSudoku(vector<vector<char> > &board) {
        // 每行1-9元素个数
        int rows[9] = {0};
        // 每列1-9元素个数
        int cols[9] = {0};
        // 每小正方格1-9元素个数
        int square[3][3] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (isdigit(c)) {
                    // 行，列，正方格元素个数出现过
                    int bit = 1 << c - '1';
                    if (bit & rows[i] || bit & cols[j] || bit & square[i / 3][j / 3]) {
                        return false;
                    }
                    rows[i] |= bit;
                    cols[j] |= bit;
                    square[i / 3][j / 3] |= bit;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char> > board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    cout << Solution().isValidSudoku(board);
    return 0;
}