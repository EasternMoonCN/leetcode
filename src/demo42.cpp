#include "utils/head.h"

/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
class Solution
{
public:
    // 对于i, j，存在i_left_max, i_right_max, j_left_max, j_right_max;
    // i < j, 由 i_left_max <= j_left_max, i_right_max >= j_right_max;
    // 若 i_left_max > j_right_max , 则 j_left_max > j_right_max，则j点可接水
    // 若 i_left_max < j_right_max , 则 i_left_max < i_right_max, 则i点可接水
    int trap(vector<int> &height)
    {
        int n = height.size(), res = 0;
        // 当前遍历left_point， right_point
        int left_point = 0, right_point = n - 1;
        // 前left_point的最大值，后right_point的最大值
        int left_max = height[left_point], right_max = height[right_point];
        while (left_point < right_point)
        {
            if (height[left_point] > height[right_point])
            {
                right_max = max(right_max, height[right_point]);
                res += right_max - height[right_point];
                right_point--;
            }
            else
            {
                left_max = max(left_max, height[left_point]);
                res += left_max - height[left_point];
                left_point++;
            }
        }

        return res;
    }
    /*
        // 第i个位置能接的水量 = min（左边最大值，右边最大值）-当前值
        int trap(vector<int>& height) {
            int res = 0, n = height.size();
            for (int i = 1; i < n; ++i) {
                int left_max = *max_element(height.begin(), height.begin() + i);
                int right_max = *max_element(height.begin() + i, height.end());
                int val_max = min(left_max, right_max);
                int temp = val_max - height[i];
                if (temp > 0) {
                    res += temp;
                }
            }
            return res;
        }
        */
};