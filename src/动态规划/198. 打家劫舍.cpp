#include "utils/common.cpp"

class Solution {
public:
    // 回溯 + 记忆搜索
    // O(N)
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        // dfs(i): 前i（0到i-1）个元素的最大金额
        auto dfs = [&](auto && dfs, int i) {
            if (i < 0) {
                return 0;
            }
            if (cache[i] != -1) {
                return cache[i];
            }

            // 第i个元素选或不选
            // 选第i个
            int d1 = nums[i] + dfs(dfs, i - 2);
            // 不选第i个
            int d2 = dfs(dfs, i - 1);
            // 计算发生在归中
            cache[i] = max(d1, d2);
            return cache[i];
        };
        return dfs(dfs, n - 1);

        // dfs(i) : 后n - i个元素的最大金额
        // auto dfs = [&](auto && dfs, int i) {
        //     if (i >= n) {
        //         return 0;
        //     }

        //     if (cache[i] != -1) {
        //         return cache[i];
        //     }

        //     // 第i个元素选或不选
        //     // 选第i个
        //     int d1 = nums[i] + dfs(dfs, i + 2);

        //     // 不选第i个
        //     int d2 = dfs(dfs, i + 1);

        //     // 计算发生在归中
        //     cache[i] = max(d1, d2);
        //     return cache[i];
        // };
        // return dfs(dfs, 0);
    }

    // 动态规划：去掉递归中递，只留下归
    int rob2(vector<int>& nums) {
        int n = nums.size();
        // if (n == 1) {
        //     return nums[0];
        // }
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for (int i = 2; i < n; ++i) {
        //     dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        // }
        // return dp[n - 1];

        // vector<int> dp(n + 2, 0);
        int f0 = 0, f1 = 0, f2;
        for (int i = 0; i < n; ++i) {
            f2 = max(f1, nums[i] + f0);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }

};