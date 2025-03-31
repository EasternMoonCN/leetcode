class Solution {
    public:
        int lengthOfLongestSubsequence(vector<int>& nums, int target) {
            int n = nums.size();
            vector<vector<int>> memory(n, vector<int>(target + 1, -target));
            auto dfs = [&](this auto&& dfs, int i, int left) -> int {
                if (i < 0) {
                    return left == 0 ? 0 : -target;
                }
                if (memory[i][left] != -target) {
                    return memory[i][left];
                }
                int n1 = -target;
                if (left >= nums[i]) {
                    n1 = dfs(i - 1, left - nums[i]) + 1;
                }
                int n2 = dfs(i - 1, left);
                memory[i][left] = max(n1, n2);
                return memory[i][left];
            };
            int res = dfs(n - 1, target);
            return res < 0 ? -1 : res;
        }

        // int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        //     int n = nums.size();
        //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, -target));
    
        //     dp[0][0] = 0;
    
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= target; ++j) {
        //             if (j >= nums[i]) {
        //                 dp[i + 1][j] = max(dp[i][j - nums[i]] + 1, dp[i][j]);
        //             } else {
        //                 dp[i + 1][j] = dp[i][j];
        //             }
        //         }
        //     }
        //     return dp[n][target] < 0 ? -1 : dp[n][target];
        // }

        // int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        //     int n = nums.size();
        //     vector<int> dp(target + 1, -target);
    
        //     dp[0] = 0;
    
        //     for (int i = 0; i < n; ++i) {
        //         // for (int j = 0; j <= target; ++j) {
        //             for (int j = target; j > 0; --j) {
        //             if (j >= nums[i]) {
        //                 dp[j] = max(dp[j - nums[i]] + 1, dp[j]);
        //                 // dp[i + 1][j] = max(dp[i][j - nums[i]] + 1, dp[i][j]);
        //             } else {
        //                 dp[j] = dp[j];
        //                 // dp[i + 1][j] = dp[i][j];
        //             }
        //         }
        //     }
        //     return dp[target] < 0 ? -1 : dp[target];
        // }
    };