#include "../utils/common.cpp"

/**
 *
 * 给定 𝑛 个物品，第 𝑖 个物品的重量为 𝑤𝑔𝑡[𝑖 − 1]、价值为 𝑣𝑎𝑙[𝑖 − 1] ，和一个容量为 𝑐𝑎𝑝 的 背包。
 * 每个物品只能选择一次，问在不超过背包容量下能放入物品的最大价值。
 */


class Solution
{
public:
    /**
     * 当前操作：枚举第i个元素选不选。不选，剩余容量不变;选，剩余容量减少w[i]
     * 子问题：前i个元素在背包容量为c下的最大价值和
     * 下一个子问题：
     *      不选：从前i-1个元素在背包容量为c下的最大价值和
     *      选：从前i-1个元素在背包容量为cap-w[i]下的最大价值
     */
    // dfs(i) ：前i个物品在cap容量下的最大价值，
    int knapsackdfs(vector<int> &wgt, vector<int> &val, int cap){
        int n = wgt.size();

        // 记忆化搜索：注意二维时cap+1
        vector<vector<int>> cache(n, vector<int>(cap + 1, -1));
        auto dfs = [&](auto&& dfs, int i, int c) {
            if (i < 0) {
                return 0;
            }

            if (cache[i][c] != -1) {
                return cache[i][c];
            }

            // 选第i个
            int v1 = 0;
            // 容量足时才能选
            if (c - wgt[i] >= 0) {
                v1 = dfs(dfs, i - 1, c - wgt[i]) + val[i];
            } 
            // 不选第i个
            int v2 = dfs(dfs, i - 1, c);
            cache[i][c] = max(v1, v2);
            return cache[i][c];
        };
        return dfs(dfs, n - 1, cap);
    }

    int knapsackdp(vector<int> &wgt, vector<int> &val, int cap){
        int n = wgt.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; ++i) {
        }
        return dp[n - 1];
    }
};

int main() {
    vector<int> wgt = {10,  20,  30,  40,  50};
    vector<int> val = {50, 120, 150, 210, 240};
    int cap = 50;
    cout << Solution().knapsackdfs(wgt, val, cap);
    return 0;
}