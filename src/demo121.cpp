#include "utils/head.h"

/*
121. 买卖股票的最佳时机

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) {
            return 0;
        }
        // 前i天最大利润
        int max_res = prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;
        // 前i-1天买入
        int min_index = max_res > 0 ? 0 : 1;
        // 以第i天卖出
        for (int i = 2; i < prices.size(); ++i) {
            if (max_res < prices[i] - prices[min_index]) {
                max_res = prices[i] - prices[min_index];
            }
            if (prices[min_index] > prices[i]) {
                min_index = i;
            }
        }
        return max_res;
    }
    /*
        int maxProfit(vector<int>& prices) {
            int max_res = 0;
            for (int i = 0; i < prices.size(); ++i) {
                for (int j = i + 1; j < prices.size(); ++j) {
                    if(max_res < prices[j] - prices[i]) {
                        max_res = prices[j] - prices[i];
                    }
                }
            }
            return max_res;
        }
        */
};