#include "../utils/common.cpp"

class Solution {
public:
    // // 时间复杂度O(n)，空间复杂度O(n)
    // // 每个位置有一个宽度为1的桶，能存储水的容量取决于左边最大高度和右边最大高度
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> pre_max(n, height[0]);
    //     vector<int> suf_max(n, height[n - 1]);
    //     // 前缀最大值
    //     for (int i = 1; i < n; ++i) {
    //         pre_max[i] = max(pre_max[i - 1], height[i]);
    //     }
    //     // 后缀最大值
    //     for (int j = n - 2; j >= 0; --j) {
    //         suf_max[j] = max(suf_max[j + 1], height[j]);
    //     }
    //     int res = 0;
    //     for (int k = 1; k < n - 1; ++k) {
    //         res += min(pre_max[k], suf_max[k]) - height[k];
    //     }
    //     return res;
        
    // }

        // 时间复杂度O(n)，空间复杂度O(1)
    // 每个位置有一个宽度为1的桶，能存储水的容量取决于左边最大高度和右边最大高度
    // 当l的前缀最大值pre_max小于r的后缀最大值suf_max，位置l的可接水容量可以计算（前缀即pre_max，后缀最小为suf_max，计算容量中取前缀和后缀的最小值，所以后缀有没有精确被计算不重要）
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int pre_max = 0, suf_max = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            pre_max = max(pre_max, height[l]);
            suf_max = max(suf_max, height[r]);

            if (pre_max < suf_max) {
                res += pre_max - height[l];
                l++;
            } else {
                res += suf_max - height[r];
                r--;
            }
        }
        return res;
        
    }
};