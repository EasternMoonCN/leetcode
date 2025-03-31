class Solution {
    public:
    // O(N)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int pre_t = INT_MIN, pre_f = 0;
        int cur_t = 0, cur_f = 0;
        for (int i = 0; i < n; ++i) {
            cur_t = max(pre_t, pre_f - prices[i]);
            cur_f = max(pre_f, pre_t + prices[i]);
            pre_t = cur_t;
            pre_f = cur_f;
        
        }
        return cur_f;
    }

        // O(N)
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            // int pre_t = 0, pre_f = INT_MIN;
            // int cur_t = 0, cur_f = 0;
            int f0 = 0, f1 = INT_MIN;
            for (int i = 0; i < n; ++i) {
                // cur_t = max(pre_t, pre_f - prices[i]);
                // cur_f = max(pre_f, pre_t + prices[i]);
                // pre_t = cur_t;
                // pre_f = cur_f;
                int new_f0 = max(f0, f1 + prices[i]);
                f1 = max(f1, f0 - prices[i]);
                f0 = new_f0;
            }
            return f0;
        }
        // O(N)
        int maxProfit(vector<int>& prices) {
        
            int n = prices.size();
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
            dp[0][1] = INT_MIN;
    
            for (int i = 0; i < n; ++i) {
                dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
                dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            }
            return dp[n][0];
        }

        // O(N)
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
                if (status) {
                    mem[i][status] =  max(dfs(i - 1, status), dfs(i - 1, !status) - prices[i]);
                } else { // 当前第i天是未持有股票状态
                    mem[i][status] =  max(dfs(i - 1, status), dfs(i - 1, !status) + prices[i]);
                }
                return mem[i][status];
            };
            // 只需要第n-1天股票是卖出状态
            return dfs(n - 1, 0);
        }
    };