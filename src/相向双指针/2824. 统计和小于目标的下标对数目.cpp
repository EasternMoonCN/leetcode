#include "../utils/common.h"

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int res = 0;
        // 因为left和right不等，所以是<
        while (left < right) {
            int total = nums[left] + nums[right];
            if (total < target) {
                // 此时小于right的和left组合，都会小于target
                res += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};