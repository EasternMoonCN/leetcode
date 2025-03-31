class Solution {
    public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> mem(n, vector<int>(2, -1));
        auto dfs = [&](auto& dfs, int i, bool status) {
            if (i < 0) {
                return status ? INT_MIN : 0;
            }
            if (mem[i][status] != -1) {
                return mem[i][status];
            }
            if (status) {
                // 不动 或 买入，费用放到买入，前一个状态是卖出，不会越界
                mem[i][status] =  max(dfs(dfs, i - 1, status), dfs(dfs, i - 1, !status) - prices[i] - fee);
            } else {
                // 不动 或 卖出
                mem[i][status] = max(dfs(dfs, i - 1, status), dfs(dfs, i - 1, !status) + prices[i]);
            }
            return mem[i][status];
        };
        return dfs(dfs, n - 1, false);
    }

        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
            dp[0][1] = INT_MIN;
            for (int i = 0; i < n; ++i) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
                // 费用放到买入的时候，就不会产生越界
                dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i] - fee);
            }
            return dp[n][0];
        }
    };