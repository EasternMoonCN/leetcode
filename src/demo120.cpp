#include "utils/common.cpp"

/**
 * 三角最小路径和
 */
class Solution {
    public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // 小标为i行有i+1个元素
        vector<vector<int>> dp(n, vector<int>(n , 0));
        dp[0][0] = triangle[0][0];
        for(int row = 1; row < n; ++row) {
            // 每一行的首列和尾列只为上一行对应元素
            dp[row][0] = dp[row - 1][0] + triangle[row][0];
            dp[row][row] = dp[row - 1][row - 1] + triangle[row][row];
            for (int col = 1; col < row; ++col) {
                dp[row][col] = min(dp[row - 1][col - 1], dp[row - 1][col]) + triangle[row][col];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

};