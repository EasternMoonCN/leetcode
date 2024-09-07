//
// Created by EasternMoon on 2024/6/27.
//
#include "utils/head.h"
/*
 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 */

class Solution {
public:
    vector<pair<int, int> > steps = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > status(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                // 回溯每一个以row，col开头
                if (backtrack(board, word, row, col, 0, status)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char> >& board, string word, int row, int col, int index, vector<vector<bool> >& status) {
        // index位置元素不相等
        if (board[row][col] == word[index]) {
            return false;
            // 最后一个元素也想等
        } else if (index == word.size() - 1) {
            return true;
        }

        // 标记当前状态已访问：可满足初始状态标记为访问
        status[row][col] = true;
        // 遍历每一个方向
        for (pair<int, int> step : steps) {
            // 每个方向行列是否满足
            if (row + step.first < 0 || row + step.first >= board.size() || col + step.second < 0 || col + step.second >= board[0].size()) {
                continue;
            }
            // 每个方向状态是否满足
            if (status[row + step.first][col + step.second]) {
                continue;
            }
            // 不需要再标记下一步状态，会在外层标记
//            status[row + step.first][col + step.second] = true;
            if (backtrack(board, word, row + step.first, col + step.second, index + 1, status)) {
                return true;
            }
//            status[row + step.first][col + step.second] = false;

        }

        // 进一步不满足，会退状态
        status[row][col] = false;

        return false;
    }
};