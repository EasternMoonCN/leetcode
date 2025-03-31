#include "../utils/common.h"

class Solution {
public:
    // 红色：target左侧
    // 蓝色：target或其右侧
    // 什么时候为蓝色
    // 1. 当 target <= 最后一个元素时， 第一种情况下，mid 在target右侧为蓝色，第二种情况下，target在第二段，mid在第二段右侧为蓝色
    // 2. 当 target >  最后一个元素时， 第一种情况下，不存在，第二种情况下，target在第一段，mid在第一段右侧（含第二段所有区域）为蓝色
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (target <= nums[n - 1]) {
                if (nums[mid] >= target && nums[mid] <= nums[n - 1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] >= target || nums[mid] <= nums[n - 1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
};