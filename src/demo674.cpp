#include "utils/head.h"

class Solution {
public:
    // 动态规划思想：dp[i]:以i为最后一位的连续递增子序列的最大长度  
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            // 当前位大于前一位，长度在前i-1个点长度长+1
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } 
            // 否则无法拼接，长度为本身
            else {
                dp[i] = 1;
            }
        }
        // 取最大的dp[i]
        return *max_element(dp.begin(), dp.end());
    }

        /*
    int findLengthOfLCIS(vector<int>& nums) {
        int max_length = 1, pre_lenght = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                pre_lenght += 1;
            } else {
                pre_lenght = 1;
            }
            max_length = max(pre_lenght, max_length);
        }
        return max_length;
    }
    */
    
};