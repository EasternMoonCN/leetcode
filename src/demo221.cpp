#include "utils/common.cpp"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        // dp[i][j]：以ij结尾的最大正方形
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = matrix[0][0] - '0';

        int res = 0;

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (matrix[row][col] - '0')
                {
                    if (row == 0 || col == 0)
                    {
                        dp[row][col] = 1;
                    }
                    else
                    {
                        // 以row，col为左下角的正方形，最大值为相邻左上，左，上 中最小值 + 1
                        dp[row][col] = min(min(dp[row - 1][col], dp[row][col - 1]), dp[row - 1][col - 1]) + 1;
                    }
                }
                res = max(res, dp[row][col]);
            }
        }
        return res * res;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int edge = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (matrix[i - 1][j - 1] - '0')
                {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) +
                        1;
                    edge = max(edge, dp[i][j]);
                }
            }
        }

        return edge * edge;
    }
};