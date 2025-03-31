#include "../utils/common.h"

class Solution {
public:
    // 如果 i< n−1 且 nums[i] < nums[i+1]，那么在下标 [i+1,n−1] 中一定存在至少一个峰值。
    // 红色：峰值左侧，不满足条件部分，目标值不可能在这
    // 蓝色：峰值及其右边，满足条件部分，目标值可能在这
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // n - 1: 一定是蓝色
        int left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left >> 1);
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            } 
        }
        return left;
    }
};