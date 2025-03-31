#include "../utils/common.h"
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            // 右指针遇到0，k减少
            if (nums[right++] == 0) {
                k--;
            }
            // k小于0，左指针左移，直到k>=0
            while (k < 0) {
                if (nums[left++] == 0) {
                    k++;
                }
            }
            res = max(res, right - left);
        }
        return res;
    }
};