class Solution {
    public:
        // o(n*amount)
        int change(int amount, vector<int>& coins) {
            int n = coins.size();
            vector<vector<int>> memory(n, vector<int>(amount + 1, -1));
            auto dfs = [&](this auto&& dfs, int i, int left) -> int{
                if (i < 0) {
                    return left == 0;
                }
                if (memory[i][left] != -1) {
                    return memory[i][left];
                }
                int n1 = 0;
                if (left >= coins[i]) {
                    n1 = dfs(i, left - coins[i]);
                }
                int n2 = dfs(i - 1, left);
                memory[i][left] =  n1 + n2;
                return memory[i][left];
            };
            return dfs(n - 1, amount);
        }

        // int change(int amount, vector<int>& coins) {
        //     int n = coins.size();
        //     vector<vector<unsigned>> dp(n + 1, vector<unsigned>(amount + 1, 0));
    
        //     // for (int i = 0; i <= n; ++i) {
        //     //     dp[i][0] = 1;
        //     // }
        //     dp[0][0] = 1;
    
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= amount; ++j) {
        //             if (j >= coins[i]) {
        //                 dp[i + 1][j] = (dp[i + 1][j - coins[i]] + dp[i][j]);
        //             } else {
        //                 dp[i + 1][j] = dp[i][j];
        //             }
        //         }
        //     }
        //     return dp[n][amount];
        
        // }

        // int change(int amount, vector<int>& coins) {
        //     int n = coins.size();
        //     vector<unsigned> dp(amount + 1, 0);
    
        //     dp[0] = 1;
    
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= amount; ++j) {
        //             if (j >= coins[i]) {
        //                 dp[j] = (dp[j - coins[i]] + dp[j]);
        //             } else {
        //                 dp[j] = dp[j];
        //             }
        //         }
        //     }
        //     return dp[amount];
        
        // }
    };