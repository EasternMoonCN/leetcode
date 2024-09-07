#include "utils/common.cpp"


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0, rows, cols);
                
            }
            if (board[r][cols - 1] == 'O') {
                dfs(board, r, cols - 1, rows, cols);
            }
        }
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') { 
                dfs(board, 0, c, rows, cols);
            }
            if (board[rows - 1][c] == 'O') {
                dfs(board, rows - 1, c, rows, cols);
            }
            
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'A') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c, const int &rows, const int& cols) {
        board[r][c] = 'A';
        if (r - 1 >= 0 && board[r - 1][c] == 'O') dfs(board, r - 1, c, rows, cols);
        if (r + 1 < rows && board[r + 1][c] == 'O') dfs(board, r + 1, c, rows, cols);
        if (c - 1 >= 0 && board[r][c - 1] == 'O') dfs(board, r, c - 1, rows, cols);
        if (c + 1 < cols && board[r][c + 1] == 'O') dfs(board, r, c + 1, rows, cols);
    }
};