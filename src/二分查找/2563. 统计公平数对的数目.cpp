#include "../utils/common.h"

class Solution {
public:
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n - 1; ++i) {
            // 找到第一个大于等于x的位置 >= x
            auto lower_it = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // 找到第一个小于等于x的位置 <= x  == > (>= x + 1) - 1
            // auto upper_it = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) -1;

            // 找到第一个小于等于x的位置 <= x  == > (> x) - 1
            auto upper_it = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - 1;

            // 由于上面求的是闭区间，所以两个相等时为1
            res += upper_it - lower_it + 1;
        }
        return res;
    }
};