#include "../utils/common.h"
class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> cache(n, -1);

    //     auto dfs = [&](auto&& dfs, int j) -> int{
    //         if (cache[j] != -1) {
    //             return cache[j];
    //         }
    //         int res = 0;
    //         // 枚举哪一个
    //         for (int i = 0; i < j; ++i) {
    //             if (nums[i] < nums[j]) {
    //                 res = max(res, dfs(dfs, i));
    //             }
    //         }
    //         cache[j] = res + 1;
    //         return cache[j];
    //     };

    //     int res = 0;
    //     for (int i = 0; i < n; ++i) {
    //         res = max(res, dfs(dfs, i));
    //     }
    //     return res;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 贪心
    int lengthOfLIS(vector<int>& nums) {
        // g[i]表示记录子序列长度为i时，对于的最小下标值
        vector<int> g;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 二分查找第一个不小于nums[i]的指针
            auto it = lower_bound(g.begin(), g.end(), nums[i]);
            if (it == g.end()) {
                g.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return g.size();
    }
};