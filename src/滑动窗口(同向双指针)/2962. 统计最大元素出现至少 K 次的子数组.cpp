#include "../utils/common.h"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0, n = nums.size();
        int left = 0, right = 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        while (right < n) {
            if (nums[right++] == max_ele) {
                k--;
            }

            while (k <= 0) {
                // 遇到了满足的字数组，right后面的数组也都满足
                res += n - right + 1;
                if (nums[left++] == max_ele) {
                    k++;
                }
            }
        }
        return res;
    }
};