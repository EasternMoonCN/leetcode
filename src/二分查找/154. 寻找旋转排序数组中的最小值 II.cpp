#include "../utils/common.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + ((right - left >> 1));
            if (nums[mid] > nums[right + 1]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right + 1]) {
                right = mid - 1;
            } else {
                right--;
            }
        }

        return nums[left];
    }
};