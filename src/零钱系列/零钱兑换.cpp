#include "../utils/common.cpp"

/**
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 */

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        // dp[i]: 金额为i时所需最小硬币数
        vector<int> dp(amount + 1, amount + 1);
        // 金额为0时，所需硬币数为0
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    // 金额为i时所需最小硬币数 = 最小值（金额为i-coin） + 1
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? - 1: dp[amount];
    }

    int coinChange2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

        // 凑成金额0元所需最小硬币数为0
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount] > amount ? - 1 : dp[n][amount];
    }
};