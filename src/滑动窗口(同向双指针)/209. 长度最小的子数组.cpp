#include "../utils/common.h"

class Solution {
public:
    // 时间复杂度O(n)：右（左）端点最多遍历n此
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, s = 0, n = nums.size(), res = n + 1;
        while (r < n) {
            s += nums[r++];

            // 单调性：从满足要求，逐渐减少，到不满足要求 或反之
            while (s - nums[l] >= target) {
                s -= nums[l++];
            }
            if (s >= target) {
                res = min(res, r - l); 
            }

            // while (s >= target) {
            //     res = min(res, r - l);
            //     s -= nums[l++];
            // }
        }
        return res == n + 1 ? 0 : res;
    }
};