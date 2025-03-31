#include "../utils/common.cpp"

/**
 * 给定 𝑛 个物品，第 𝑖 个物品的重量为 𝑤𝑔𝑡[𝑖 − 1]、价值为 𝑣𝑎𝑙[𝑖 − 1] ，和一个容量为 𝑐𝑎𝑝 的 背包。
 * 每个物品可以重复选取，问在不超过背包容量下能放入物品的最大价值。
 */

class Solution
{
    public:
    int unboundedKnapsack2(vector<int> &wgt, vector<int> &val, int cap)
    {
        int n = wgt.size();
        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= cap; ++j) {
                if (j - wgt[i - 1] >= 0) {
                    // 选与不选物品i的最大价值
                    dp[i][j] = max(dp[i][j - wgt[i - 1]] + val[i - 1], dp[i - 1][j]);
                } else {
                    // 容量不足，只能不选
                    dp[i][j] = dp[i - 1][j];
                }
                
            }
        }
        return dp[n][cap];
    }

    int unboundedKnapsack(vector<int> &wgt, vector<int> &val, int cap)
    {
        int n = wgt.size();
        // dp[i]: 容量为i时，最大价值
        vector<int> dp(cap + 1, 0);
        dp[0] = 0;
        

        for (int i = 1; i <= n; ++i) {
            // 正序遍历，dp依赖于上边和左边
            for (int j = 1; j <= cap; ++j) {
                if (j - wgt[i - 1] >= 0) {
                    dp[j] = max(dp[j], dp[j - wgt[i - 1]] + val[i - 1]);
                }
            }
        }
        common<int>::printVector(dp);
        return dp[cap];
    }
};

int main() {
    vector<int> wgt = {10,  20,  30,  40,  50};
    vector<int> val = {50, 120, 150, 210, 240};
    int cap = 50;
    cout << Solution().unboundedKnapsack2(wgt, val, cap);
    return 0;
}