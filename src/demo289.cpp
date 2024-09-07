//
// Created by EasternMoon on 2024/6/24.
//
#include "utils/head.h"
class Solution {
public:
    int sumAround(vector<vector<int> >& board, int row, int col, int m, int n) {
        int sum = 0;
        for(int i = max(row - 1, 0); i < min(m, row + 2); ++i) {
            for(int j = max(col - 1, 0); j < min(n , col + 2); ++j) {
                if(row == i && col == j) {
                    continue;
                }
                sum += board[i][j];
            }
        }
        return sum;
    }
    
    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int> > res(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum = sumAround(board, i, j, m, n);
                if(board[i][j]) {
                    if(sum == 2 || sum == 3) {
                        res[i][j] = 1;
                    }
                } else {
                    if(sum == 3) {
                        res[i][j] = 1;
                    }
                }
            }
        }
        board = res;
    }
};

int main() {
    vector<vector<int> > board = {{1, 1}, {1, 0}};
    Solution().gameOfLife(board);
}