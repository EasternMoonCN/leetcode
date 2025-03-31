#include "utils/common.h"

/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b1 = -prices[0], b2 = -prices[0], s1 = 0, s2= 0;

        for (int i = 0; i < n; ++i) {
            // 第一次买入:始终在寻找买入时最高利润(以最低价买入)
            b1 = max(b1, -prices[i]);
            // 第一次售出
            s1 = max(s1, b1 + prices[i]);
            // 第二次买入(取最大值保留了第一次买卖利润)
            b2 = max(b2, s1 - prices[i]);
            // 第二次售出
            s2 = max(s2, b2 + prices[i]);
        }
        return s2;
    }
};