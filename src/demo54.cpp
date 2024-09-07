//
// Created by EasternMoon on 2024/6/22.
//
#include "utils/head.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            // 第一行(全部)
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            // 最后一列（从第二个开始，到最后一个）
            for (int i = top + 1; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            // 是否存在从右到左，从下到上
            if (left < right && top < bottom) {
                // 最后一行（从倒数第二个开始，到第二个）
                for (int i = right - 1; i > left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                // 第一列（从倒数第一个开始，到第二个）
                for (int i = bottom; i > top; --i) {
                    res.push_back(matrix[i][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
/*    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = 0;
        // 1,2,3,4 右，下，左，上
        int direct = 1, loop = 0;
        vector<int> res;

        while (row < rows && col < cols) {
            res.push_back(matrix[row + loop][col + loop]);
            if (direct == 1) {
                if (col < cols - 1) {
                    ++col;
                } else {
                    ++row;
                    ++direct;
                }

            } else if (direct == 2) {
                if (row < rows - 1) {
                    ++row;
                } else {
                    --col;
                    ++direct;
                }

            } else if (direct == 3) {
                if (col > 0) {
                    --col;
                } else {
                    --row;
                    ++direct;
                }
            } else {
                if (row > 1) {
                    --row;
                } else {
                    direct = 1;
                    rows -= 2;
                    cols -= 2;
                    row = 0;
                    col = 0;
                    ++loop;
                }
            }
        }

        return res;
    }*/
};

void print(int val) {
    cout << val << " ";
}

int main() {
//    vector<vector<int> > matrix = {{1, 2, 3},
//                                   {4, 5, 6},
//                                   {7, 8, 9}};

//    vector<vector<int> > matrix = {{1, 2,  3,  4},
//                                   {5, 6,  7,  8},
//                                   {9, 10, 11, 12}};
vector<vector<int> > matrix = {{3},{2}};
//vector<vector<int> > matrix = {{1,2},{3,4}};
    vector<int> res = Solution().spiralOrder(matrix);
    for_each(res.begin(), res.end(), print);
}
