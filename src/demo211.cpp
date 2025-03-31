#include "utils/common.cpp"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        // dp[i][j]：以ij结尾的最大正方形,且表示以ij结尾边长为dp[i][j]的正方形个数
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = matrix[0][0] - '0';

        int res = dp[0][0];
        for (int row = 1; row < rows; ++row)
        {
            dp[row][0] = matrix[row][0] - '0';
            res = max(res, dp[row][0]);
        }
        for (int col = 1; col < cols; ++col)
        {
            dp[0][col] = matrix[0][col] - '0';
            res = max(res, dp[0][col]);
        }

        for (int row = 1; row < rows; ++row)
        {
            for (int col = 1; col < cols; ++col)
            {
                if (matrix[row][col] - '0') {
                    // 以row，col为左下角的正方形，最大值为相邻左上，左，上 中最小值 + 1
                    dp[row][col] = min(min(matrix[row - 1][col], matrix[row][col - 1]), matrix[row - 1][col - 1]) + 1;
                } else {
                    dp[row][col] = 0;
                }
                res = max(res, dp[row][col]);
            }
        }
        return res;
    }

    // 暴力法
    int maximalSquare2(vector<vector<char>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();

        int side = 0;

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (matrix[row][col] == '1')
                {
                    side = max(1, side);
                    // 以row，col为左上角最大能取到到边的长度
                    int maxSide = min(rows - 1 - row, cols - 1 - col);
                    for (int k = 1; k <= maxSide; k++)
                    {
                        // 判断对角线
                        if (matrix[row + k][col + k] == '0')
                        {
                            break;
                        }
                        
                        // 表示长度为k是否能组成正方形
                        bool flag = true;
                        // 判断长度为k的行列
                        for (int m = 0; m < k; m++)
                        {
                            if (matrix[row + m][col + k] == '0' || matrix[row + k][col + m] == '0')
                            {
                                flag = false;
                                break;
                            }
                        }

                        if (flag)
                        {
                            side = max(side, k + 1);
                        } else {
                            // 长度为k不能组成正方形，则无需继续遍历
                            break;
                        }
                    }
                }
            }
        }
        return side * side;
    }
};

int main()
{
    vector<vector<char>> matrix = {
        {'0','1','1','0','1'},
        {'1','1','0','1','0'},
        {'0','1','1','1','0'},
        {'1','1','1','1','0'},
        {'1','1','1','1','1'},
        {'0','0','0','0','0'}
        };
    cout << Solution().maximalSquare2(matrix);
}