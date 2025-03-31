#include "../utils/common.cpp"

class Solution {
public:
    // 两种情况1. 递增， 2.两端递增，第一段全大于第二段
    // 红色：最小值左侧
    // 蓝色：最小值及其右侧
    // 最后一个元素一定是蓝色，要么是最小值，要么在最小值右侧
    // nums[mid] < 最后一个元素：1. 最小值或其右侧 2. 在第二段，最小值及其右侧，染成蓝色
    // nums[mid] > 最后一个元素：1. 不可能 2. 在第一段，最小值左侧，染成红色
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left >> 1);
            // if (nums[mid] < nums[right + 1]) {
            if (nums[mid] < nums[n - 1]) {
                right = mid - 1;
            } else { // 元素不相等
                left = mid + 1;
            }
        }
        return nums[left];
    }
};