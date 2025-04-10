#include "../utils/common.cpp"

/**
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 假设每一种面额的硬币有无限个。 
 * 题目数据保证结果符合 32 位带符号整数。
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i] ：前i个组合数
        vector<int> dp(amount + 1, 0), valid(amount + 1, 0);;

        dp[0] = 1;
        valid[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    valid[j] = valid[j] | valid[j - coins[i - 1]];
                }
            }
        }
        if (!valid[amount]) {
            return 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                }
            }
        }

        return dp[amount];
    }

    int change2(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // 金额为0组合数为1
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};