#include "../utils/common.h"

class Solution {
public:
    // 从nums中寻找最长子数组，和为s-x
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), -x);
        if (target < 0) {
            return -1;
        }
        int left = 0, right = 0, n = nums.size();
        int sum = 0, res = -1;
        while (right < n) {
            sum += nums[right++];

            while (sum > target) {
                sum -= nums[left++];
            }
            if (sum == target) {
                res = max(res, right - left);
            }

        }
        return res == -1 ? res : n - res;
    }
};