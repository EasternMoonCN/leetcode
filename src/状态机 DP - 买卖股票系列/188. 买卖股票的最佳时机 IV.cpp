class Solution {
    public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(k + 2, vector<int>(2, 0)));
        
        for (int j = 0; j <= k + 1; ++j) {
            dp[0][j][1] = -1001;
        }

        for (int i = 0; i <= n; ++i) {
            dp[i][0][0] = -1001;
            dp[i][0][1] = -1001;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                dp[i + 1][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][1] + prices[i]);
                dp[i + 1][j + 1][1] = max(dp[i][j + 1][1], dp[i][j + 1][0] - prices[i]);
                res = max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][0]);
            }
        }
        return res;
    }
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> mem(
                n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
            auto dfs = [&](this auto&& dfs, int i, int j, bool status) {
                // 此次交易不成功
                if (j < 0) {
                    return -1001;
                }
                if (i < 0) {
                    return status ? -1001 : 0;
                }
                if (mem[i][j][status] != -1) {
                    return mem[i][j][status];
                }
                // 第i天持有
                if (status) { // 买入
                    // 卖出的时候不用计算交易次数
                    mem[i][j][status] = max(dfs(i - 1, j, status), dfs(i - 1, j, !status) - prices[i]);
                } else {
                    // 买入的时候计算一次交易，卖出
                    mem[i][j][status] = max(dfs(i - 1, j, status), dfs(i - 1, j - 1, !status) + prices[i]);
                }
                return mem[i][j][status];
            };
            return dfs(n - 1, k, false);
        }
    };