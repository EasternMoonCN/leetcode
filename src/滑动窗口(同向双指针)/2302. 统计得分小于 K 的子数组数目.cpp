#include "../utils/common.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, sum = 0;
        int left = 0, right = 0;
        int n = nums.size();
        while (right < n) {
            sum += nums[right++];
            while (sum * (right - left) >= k) {
                sum -= nums[left++];
            }
            // 以right - 1 为结束，能形成right - left 个字数组
            res += right - left;
        }
        return res;
    }
};