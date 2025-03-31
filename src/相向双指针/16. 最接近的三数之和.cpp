#include "../utils/common.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, closed = INT_MAX, n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (closed > abs(target - total)) {
                    closed = abs(target - total);
                    res = total;
                }
                if (total < target) {
                    // 需要增加目标和
                    left++;
                } else {
                    // 需要减少目标和
                    right--;
                }
            }
        }
        return res;
    }
};