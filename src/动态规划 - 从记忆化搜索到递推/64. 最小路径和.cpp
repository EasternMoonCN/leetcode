#include "../utils/common.cpp"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memory(n, vector<int>(m, -1));
        auto dfs = [&](this auto && dfs, int i, int j) -> int {
            if (i == 0 && j == 0) {
                return grid[0][0];
            }
            if (memory[i][j] != -1) {
                return memory[i][j];
            }
            int v1 = INT_MAX, v2 = INT_MAX;
            if (i > 0) {
                v1 = dfs(i - 1, j);
            }
            if (j > 0) {
                v2 = dfs(i, j - 1);
            }
            memory[i][j] = grid[i][j] + min(v1, v2);
            return memory[i][j];
        };
        return dfs(n - 1, m - 1);
    }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    //     dp[0][0] = grid[0][0];
    //     for (int i = 1; i < n; ++i) {
    //         dp[i][0] = grid[i][0] + dp[i - 1][0];
    //     }
    //     for (int j = 1; j < m; ++j) {
    //         dp[0][j] = grid[0][j] + dp[0][j - 1];
    //     }

    //     for (int i = 1; i < n; ++i) {
    //         for (int j = 1; j < m; ++j) {
    //             dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    //     return dp[n - 1][m - 1];
    // }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    return Solution().minPathSum(grid);
}