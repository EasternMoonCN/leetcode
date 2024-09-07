#include "utils/head.h"
/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

class Solution {
public:

    
    //    dp[i]: 以第 i 个数结尾的「连续子数组的最大和」
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max_res, pre_val;
        pre_val = max_res = nums[0];
        for (int i = 1; i < n; ++i) {
            pre_val = max(pre_val + nums[i], nums[i]);
            max_res = max(max_res, pre_val);
        }
        return max_res; 
    }

    /*
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            // 当前位置带不带上前面的值？
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end()); 
    }*/


    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int dp[n][n];

    //     for(int i = 0; i < n; ++i) {
    //         for(int j = 0; j < n; ++j) {
    //             dp[i][j]= 0;
    //         }
    //     }
    // }

    
};