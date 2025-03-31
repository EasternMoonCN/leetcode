#include "../utils/common.cpp"

class Solution {
public:

    /**
     * 当前操作：枚举第i种物品选或不选。不选，剩余金额不变；选，剩余金额减少coins[i]
     * 
     * 子问题：在剩余金额为c时，从前i种物品中得到的最小硬币数
     * 
     * 下一个子问题：
     *      不选：在剩余容量为c时，从前i种物品中得到的最小硬币数
     *      选：在剩余容量为c-coins[i]时，从前i种物品中得到的最小硬币数
     */
    int coinChangeDfs(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        auto dfs = [&](auto&& dfs, int i, int c) {
            if (i < 0) {
                return c == 0 ? 0 : amount + 1;
            }


            if (c >= coins[i]) {
                return min(dfs(dfs, i, c - coins[i]) + 1, dfs(dfs, i - 1, c)); 
            }

            return dfs(dfs, i - 1, c);
        };

        int r = dfs(dfs, n - 1, amount) ;
        return r == amount + 1 ? -1 : r;
    }

    int coinChangeDp2(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i]) {
                    dp[i + 1][j] = min(dp[i + 1][j - coins[i]] + 1,
                    dp[i][j]);
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
    }

    int coinChangeDp1(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i]) {
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                } 
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {2, 5, 10, 1};
    int amount = 27;
    cout << Solution().coinChangeDp2(coins, amount);
}