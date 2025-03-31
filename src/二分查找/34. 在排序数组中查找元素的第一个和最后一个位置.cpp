#include "../utils/common.h"

/**
 * 
 * 二分查找
 * 闭区间[l, r], 结束条件 l <= r, 即r + 1 = l时终止， 循环不变量 <= l - 1 不满足条件，>= r + 1 满足条件
 * 左闭右开区间[l, r), 结束条件 l < r，即l = r时终止，循环不变量 <= l - 1 不满足条件， >= r 满足条件
 * 开区间(l, r), 结束条件l + 1 < r， 即 l + 1 = r 时终止， 循环不变量 <= l 不满足条件，>= r 满足条件
 * 
 * target 整数情况下
 * >= target
 * >  target  ==>  >= target + 1
 * <  target  ==>  (>= target ) - 1
 * <= target  ==>  (> target) - 1
 */
// class Solution {
// public:
//     // O(log n)
//     int lower_bound(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1; // 闭区间[left, right]
//         int m;
//         while (l <= r) {    // r跑到l左边，区间不存在
//             m = l + ((r - l) >> 1);
//             if (nums[m] < target) {
//                 // 闭区间[m + 1, right]
//                 l = m + 1;
//             } else {
//                 // 闭区间   [l, mid - 1]
//                 r = m - 1;
//             }
//         }
//         return l;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         // >= target
//         int start = lower_bound(nums, target);
//         if (start == nums.size() || nums[start] != target) {
//             return {-1, -1};
//         }
//         // <= target  ==>  (> target) - 1 => (>= target + 1) - 1
//         int end = lower_bound(nums, target + 1) - 1;
//         return {start, end};
//     }
// };


class Solution {
public:
    // 红色：target 左边
    // 蓝色：target 或 其右边
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto lower_bound = [&](int t) -> int {
            // target 可能大于最后的元素，所以最后的元素不一定在target左边
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;

                // mid 及其左边的元素为红色 -> left 左边的元素为红色
                if (nums[mid] < t) {
                    left = mid + 1;
                } else {
                    // mid即其右边的元素为蓝色-> right 右边元素为蓝色
                    right = mid - 1;
                }
            }
            return left;
        };
        int low = lower_bound(target);
        if (low == n || nums[low] != target) {
            return {-1, -1};
        }
        int upper = lower_bound(target + 1) - 1;
        return {low, upper};
    }
};