class Solution {
    public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 前1天不持有， 前1天持有， 前2天不持有
        int f10 = 0, f11 = INT_MIN, f20 = 0;
        for (int i = 0; i < n; ++i) {
            int new_f10 = max(f10, f11 + prices[i]);
            f11 = max(f11, f20 - prices[i]);
            f20 = f10;
            f10 = new_f10;
        }
        return f10;
}


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        dp[1][1] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            dp[i + 2][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
            dp[i + 2][1] = max(dp[i + 1][1], dp[i][0] - prices[i]);
        }
        return dp[n + 1][0];
}
        int maxProfit(vector<int>& prices) {
                int n = prices.size();
                // dfs(i, 0) ：第i天不持有股票最大利润
                // dfs(i, 1) ：第i天持有股票最大利润
                vector<vector<int>> mem(n, vector<int>(2, -1));
                auto dfs = [&](this auto && dfs, int i, bool status)->int {
                    if (i < 0) {
                        // i小于0情况下，不可能持有股票
                        return status ? INT_MIN : 0;
                    }
        
                    if (mem[i][status] != -1) {
                        return mem[i][status];
                    }
                    // 当前第i天是持有股票状态
                    if (status) { // true：买入股票
                        // i - 2 ：买入股票必须隔一天，前一次一定是卖出
                        mem[i][status] =  max(dfs(i - 1, status), dfs(i - 2, !status) - prices[i]);
                    } else { // 当前第i天是未持有股票状态
                        mem[i][status] =  max(dfs(i - 1, status), dfs(i - 1, !status) + prices[i]);
                    }
                    return mem[i][status];
                };
                // 只需要第n-1天股票是卖出状态
                return dfs(n - 1, 0);
        }
    };