#include "../utils/common.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int l = 0, r = 0, mul = 1, res = 0, n = nums.size();
        while (r < n) {
            mul *= nums[r++];

            // 单调性：从不满足要求，逐渐减少，到满足要求 或反之
            while (mul >= k) {
                mul /= nums[l++];
            }
            if (mul < k) {
                // 以 r - 1为右端点，l - 1为左端点个数
                res += r - l;
            }
        }
        return res;
    }
};