#include "utils/common.h"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1;
        for (int row = 1; row < rows; row++)
        {
            dp[row][0] = dp[row - 1][0];
        }
        for (int col = 1; col < cols; col++)
        {
            dp[0][col] = dp[0][col - 1];
        }

        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                if (obstacleGrid[row][col])
                {
                    dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};