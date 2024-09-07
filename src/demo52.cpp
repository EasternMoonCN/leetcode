//
// Created by EasternMoon on 2024/6/26.
//
#include "utils/head.h"
/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 */

class Solution {
public:
    // 主角角线 行 - 列 相等， 副对角线 行 + 列 相等
    int totalNQueens(int n) {
        int sum = 0;
        backtrack(0, n, vector<int>(n, 0), vector<int>(2*n - 1), vector<int>(2*n - 1), sum);
        return sum;
    }

    void backtrack(int row, int n, vector<int> cols, vector<int> mainDiag, vector<int> secDiag, int& sum) {
        if(row == n) {
            sum++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || mainDiag[row - col + n - 1] || secDiag[row + col]) {
                continue;
            }
            cols[col] = 1;
            mainDiag[row - col + n - 1] = 1;
            secDiag[row + col] = 1;
            backtrack(row + 1, n, cols, mainDiag, secDiag, sum);
            cols[col] = 0;
            mainDiag[row - col + n - 1] = 0;
            secDiag[row + col] = 0;
        }
    }
};

int main() {
    cout << Solution().totalNQueens(4);
}