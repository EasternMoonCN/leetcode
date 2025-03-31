#include "../utils/common.cpp"

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int maximumCount(vector<int>& nums) {
        // <= 0 坐标
        int neg = lower_bound(nums, 0);
        // if (neg == nums.size() || nums[neg] != 0) {

        // }
        // >= 0 == >  <=(0 + 1) - 1
        // > 0  == >  <=(0 + 1)
        int pos = nums.size() - lower_bound(nums, 1);
        return max(neg, pos);
    }
};