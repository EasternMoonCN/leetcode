#include "../utils/common.cpp"

/**
 * 给定 𝑛 个物品，第 𝑖 个物品的重量为 𝑤𝑔𝑡[𝑖 − 1]、价值为 𝑣𝑎𝑙[𝑖 − 1] ，和一个容量为 𝑐𝑎𝑝 的 背包。
 * 每个物品可以重复选取，问在不超过背包容量下能放入物品的最大价值。
 */

class Solution
{
public:
    /**
     * 当前操作：枚举第i种物品选或不选。不选，剩余容量不变；选，剩余容量减少w[i]
     * 
     * 子问题：在剩余容量为c时，从前i种物品中得到的最大价值和
     * 
     * 下一个子问题：
     *      不选：在剩余容量为c时，从前i-1种物品中得到的最大价值和
     *      选：在剩余容量为c-w[i]时，从前i种物品中得到的最大价值和
     */
    int unboundedKnapsackdfs(vector<int> &wgt, vector<int> &val, int cap)
    {
        int n = wgt.size();
        vector<vector<int>> cache(n, vector<int>(cap + 1, -1));
        auto dfs = [&](auto&& dfs, int i, int c) {
            if (i < 0) {
                return 0;
            }

            if (cache[i][c] != -1) {
                return cache[i][c];
            }

            // 选
            int v1 = 0;
            if (c - wgt[i] >= 0) {
                v1 = dfs(dfs, i, c - wgt[i]) + val[i]; 
            }

            // 不选
            int v2 = dfs(dfs, i - 1, c);
            cache[i][c] = max(v1, v2);
            return cache[i][c];
        };

        return dfs(dfs, n - 1, cap);
    }

    int unboundedKnapsackdp(vector<int> &wgt, vector<int> &val, int cap) {
        int n = wgt.size();
        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < cap; ++j) {
                if (j >= wgt[i]) {
                    dp[i + 1][j] = max(dp[i + 1][j - wgt[i]] + val[i], dp[i][j]);
                } else {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }

        return dp[n][cap];
    }
};


int main() {
    vector<int> wgt = {10,  20,  30,  40,  50};
    vector<int> val = {50, 120, 150, 210, 240};
    int cap = 50;
    cout << Solution().unboundedKnapsackdfs(wgt, val, cap);
    return 0;
}