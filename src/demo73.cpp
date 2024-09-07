//
// Created by EasternMoon on 2024/6/23.
//
#include "utils/head.h"

/*
 73. 矩阵置零
 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 */
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > res(m, vector<int>(n, 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // 标记i行所有列
                    for (int k = 0; k < n; ++k) {
                        res[i][k] = 0;
                    }
                    // 标记j列所有行
                    for (int k = 0; k < m; ++k) {
                        res[k][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] &= res[i][j];
            }
        }
    }
};