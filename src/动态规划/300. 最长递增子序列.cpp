#include "../utils/common.cpp"


class Solution {
public:
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    // o(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // tails[i] ：递增子序列长度为i的最小尾元素
        vector<int> tails;

        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            // 可以增加子序列长度
            if (it == tails.end()) {
                tails.push_back(nums[i]);
            } else {
                // 找到一个新的子序列（尾元素更小）
                *it = nums[i];
            }
        }
        return tails.size();
    }
};