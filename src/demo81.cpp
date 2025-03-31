#include "utils/common.cpp"

class Solution {
public:

    bool isSingle(vector<int>& nums, int start, int end) {
        int base = nums[start];
        for (int i = start + 1; i < end; ++i) {
            if (nums[i] != base) {
                return false;
            }
        }
        return true;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            // 左边，中间，右边都一致, 解决只有一个元素不同的情况(1 0 1 1 1)
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // 左边小于中间，或时同一个元素
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) { // 目标在左边
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // 右边有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }

    bool isSingle(vector<int>& nums, int start, int end) {
        int base = nums[start];
        for (int i = start + 1; i < end; ++i) {
            if (nums[i] != base) {
                return false;
            }
        }
        return true;
    }
    int search2(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            // 左边小于中间元素 或 只有一个元素 或 左边元素都相同
            if (nums[left] < nums[mid] || left == mid || (nums[left] == nums[mid] && isSingle(nums, left, mid))) {
                if (target >= nums[left] && target < nums[mid]) { // 目标在左边
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // 右边有序
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};