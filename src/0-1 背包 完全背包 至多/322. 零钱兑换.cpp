class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            vector<vector<int>> memory(n, vector<int>(amount + 1, -1));
            auto dfs = [&](this auto&& dfs, int index, int left) -> int {
                if (index < 0) {
                    return amount + 1;
                }
                if (left == 0) {
                    return 0;
                }
                if (memory[index][left] != -1) {
                    return memory[index][left];
                }
                int n1 = amount + 1;
                if (left >= coins[index]) {
                    n1 = dfs(index, left - coins[index]) + 1;
                }
                int n2 = dfs(index - 1, left);
                memory[index][left] = min(n1, n2);
                return memory[index][left];
            };
            int res = dfs(n - 1, amount) ;
            return res == amount + 1 ? -1 : res;
        }

        // int coinChange(vector<int>& coins, int amount) {
        //     int n = coins.size();
        //     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    
        //     for (int j = 0; j <= amount; ++j) {
        //         dp[0][j] = amount + 1;
        //     }
    
        //     for (int i = 0; i <= n; ++i) {
        //         dp[i][0] = 0;
        //     }
    
    
        //     for (int i = 1; i <= n; ++i) {
        //         for (int j = 1; j <= amount; ++j) {
        //             if (j >= coins[i - 1]) {
        //                 dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
        //             } else {
        //                 dp[i][j] = dp[i - 1][j];
        //             }
                    
        //         }
        //     }
    
        //     return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
        // }


        // int coinChange(vector<int>& coins, int amount) {
        //     int n = coins.size();
        //     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
    
        //     dp[0][0] = 0;
    
        //     // i对于coins来说是下标，i = 0 时，表示coins[0]
        //     // i对于dp来说是第几个，i=0时，表示第一个硬币
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= amount; ++j) {
        //             if (j >= coins[i]) {
        //                 dp[i + 1][j] = min(dp[i + 1][j - coins[i]] + 1, dp[i][j]);
        //             } else {
        //                 dp[i + 1][j] = dp[i][j];
        //             }
                    
        //         }
        //     }
    
        //     return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
        // }

        // int coinChange(vector<int>& coins, int amount) {
        //     int n = coins.size();
        //     vector<int> dp(amount + 1, amount + 1);
    
        //     dp[0] = 0;
    
        //     // i对于coins来说是下标，i = 0 时，表示coins[0]
        //     // i对于dp来说是第几个，i=0时，表示第一个硬币
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= amount; ++j) {
        //             if (j >= coins[i]) {
        //                 // 更新后的本行，所以时正序
        //                 dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        //                 // dp[i + 1][j] = min(dp[i + 1][j - coins[i]] + 1, dp[i][j]);
        //             } else {
        //                 dp[j] = dp[j];
        //                 // dp[i + 1][j] = dp[i][j];
        //             }
                    
        //         }
        //     }
    
        //     return dp[amount] == amount + 1 ? -1 : dp[amount];
        // }
    };