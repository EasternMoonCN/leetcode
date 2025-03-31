#include "../utils/common.h"

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        auto check = [&](int num) -> bool {
            long long extra = 0;
            for (int i = nums.size() - 1; i > 0; --i) {
                // extra类似进位，低i位达到要求后，i-1位需要增加多少
                extra = max(nums[i] + extra - num, 0LL);
            }
            return nums[0] + extra <= num;
        };

        int left = 0, right = max_val;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};