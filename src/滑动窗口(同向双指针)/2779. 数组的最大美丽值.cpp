#include "../utils/common.h"

class Solution {
public:
    // 排序后，问题变成寻找nums[j] - nums[i] <= 2k 的最长子串
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0, right = 0;
        int res = 0;

        while (right < n) {
            int num = nums[right++];
            while (num - nums[left] > 2 * k) {
                left++;
            }
            res = max(right - left, res);
        }

        return res;
    }
};