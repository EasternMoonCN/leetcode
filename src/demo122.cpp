#include "utils/head.h"

/*
122. 买卖股票的最佳时机 II
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp:前i天不持有股票，持有股票的最大利润
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++ i) {
            // 第i天不持有股票=第i-1天不持有股票，第i-1天持有股票第i天卖出 之间最大值
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
    /*
        int maxProfit(vector<int>& prices) {
            int max_sum = 0, min_profit = INT_MAX;
            for (int i = 0; i < prices.size(); ++i) {
                // 是否能构成一次交易：第i天卖出
                if (prices[i] - min_profit > 0) {
                    max_sum += prices[i] - min_profit;
                    // 当前完成一次交易，更新最小买入值从当前位置i开始
                    min_profit = prices[i];
                }
                // 前i天买入最低值
                if (min_profit > prices[i]) {
                    min_profit = prices[i];
                }
            }
            return max_sum;
        }
        */
};