#include "utils/common.cpp"

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[i] : 价值i至少需要dp[i] 枚硬币
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            int minCount = INT_MAX;
            for (int coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] != -1)
                {
                    minCount = min(minCount, dp[i - coin]);
                }
            }
            dp[i] = minCount == INT_MAX ? -1 : minCount;
        }
        return dp[amount];
    }

    int coinChange2(vector<int> &coins, int amount)
    {
        // dp[i] : 价值i至少需要dp[i] 枚硬币, 由于coins中最小值为1，则最多需要amount枚硬币
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i - coin >= 0)
                {
                    // 无法表示的话，dp[i - coint]+1会越来越大
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        // 超过多大硬币数量，则无法构成
        return dp[amount] > amount ? -1 : dp[amount];
    }

    int dfs(vector<int> &coins, int amount, int count)
    {
        if (amount == 0)
        {
            return count;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }

        int minCount = INT_MAX;
        for (int coin : coins)
        {
            minCount = min(minCount, dfs(coins, amount - coin, count + 1));
        }
        return minCount;
    }

    int coinChange3(vector<int> &coins, int amount)
    {
        int count = dfs(coins, amount, 0);
        return count == INT_MAX ? -1 : count;
    }
};