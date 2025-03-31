class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        auto dfs = [&](this auto && dfs, int i, int t) -> int {
            if (i < 0) {
                return t == 0;
            }
            // 选正
            int v1 = dfs(i - 1, t - nums[i]);
            // 选负
            int v2 = dfs(i - 1, t + nums[i]);
            return v1 + v2;
        };
        return dfs(n - 1, target);
    }

    //     int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int s = accumulate(nums.begin(), nums.end(), target);
    //     if (s < 0 || s % 2 != 0) {
    //         return 0;
    //     }
    //     int p = s >> 1;
    //     vector<vector<int>> memory(n, vector<int>(p + 1, -1));

    //     auto dfs = [&](this auto && dfs, int i, int t) -> int {
    //         if (i < 0) {
    //             return t == p;
    //         }
    //         if (memory[i][t] != -1) {
    //             return memory[i][t];
    //         }
    //         // 选
    //         int v1 = 0;
    //         if (t + nums[i] <= p) {
    //             v1 = dfs(i - 1, t + nums[i]);
    //         }
    //         // 不选
    //         int v2 = dfs(i - 1, t);
    //         memory[i][t] = v1 + v2;
    //         return memory[i][t];
    //     };
    //     return dfs(n - 1, 0);
    // }

    //     int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int s = accumulate(nums.begin(), nums.end(), target);
    //     if (s < 0 || (s & 1)) {
    //         return 0;
    //     }
    //     int p = s >> 1;
    //     vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    //     dp[0][0] = 1;

    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j <= p; ++j) {
    //             if (j >= nums[i]) {
    //                 dp[i + 1][j] = dp[i][j - nums[i]] + dp[i][j];
    //             } else {
    //                 dp[i + 1][j] = dp[i][j];
    //             }
    //         }
    //     }
    //     return dp[n][p];
    // }
};