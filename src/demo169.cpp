#include "utils/head.h"

/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。


*/
class Solution {
public:

    
    int countElement(vector<int> &nums, int left, int right, int majority)
    {
        int res = 0;
        while (left <= right)
        {
            if (nums[left] == majority)
            {
                ++res;
            }
            ++left;
        }
        return res;
    }

    // 二分：如果majority是left，right中的多数元素，则majority至少是left，m 或 m+1， right其中之一的多数元素
    int majorityElement(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        // 中位数
        int m = left + ((right - left) >> 1);
        // 左边的多位元素
        int left_majority = majorityElement(nums, left, m);
        // 右边多位元素
        int right_majority = majorityElement(nums, m + 1, right);
        if (left_majority == right_majority) {
            return left_majority;
        }
        // 计算left_majority 在[left, right] 中出现次数
        int left_count = countElement(nums, left, right, left_majority);
        int right_count = countElement(nums, left, right, right_majority);
        // 返回较多次数
        return left_count > right_count ? left_majority : right_majority;
    }

    int majorityElement(vector<int> &nums)
    {
        int m = nums.size();
        return majorityElement(nums, 0, m - 1);
    }
    /*
    int majorityElement(vector<int>& nums) {
        // num -> count
        unordered_map<int, int> map;
        int res = nums[0];
        for (int num : nums) {
            ++map[num];
            if (map[num] > map[res]) {
                res = num;
            }
        }
        return res;
    }
    */

    /*
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    */
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << Solution().majorityElement(nums);
}
