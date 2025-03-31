#include "utils/common.cpp"

/**
 * 最长严格递增子序列
 */
class Solution {
    vector<int> record;
    int maxLatest = 1;
    public:
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size(), res = 1;
        // dp[i] 以第i个数字结尾是的最长严格递增子序列
        // dp[i] 以第i个结尾，在前i-1个中选择最大的dp[j]时，是以nums[j]结尾的，此时只需要保证nums[i] > nums[j]
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        record.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            dfs(nums, i);
        }
        return maxLatest;
    }

    int dfs(vector<int> nums, int cur) {
        if (cur == 0) 
        {
            return 1;
        }
        if (record[cur]) {
            return record[cur];
        }

        int latest = 1;
        for (int i = cur - 1; i >= 0; i--)
        {
            if (nums[cur] > nums[i]) {
                latest = max(latest, dfs(nums, i) + 1);
            }
        }
        record[cur] = latest;
        maxLatest = max(maxLatest, latest);
        return latest;
    
    }

};