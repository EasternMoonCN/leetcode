#include "utils/head.h"


/*
238. 除自身以外数组的乘积

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。


*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1, n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            res[i] *= prefix;
            res[j] *= suffix;
            prefix *= nums[i];
            suffix *= nums[j];
        }
        return res;
    }

    /*
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size(), prefixProduct = 1, suffixProduct = 1;
            vector<int> prefix(n, 1), suffix(n, 1);
            // 提前计算每个元素前缀后缀积
            for (int i = 0; i < n; ++i) {
                prefixProduct *= nums[i];
                prefix[i] = prefixProduct;

                suffixProduct *= nums[n - i - 1];
                suffix[n - i -1] = suffixProduct;
            }

            vector<int> res(n, 0);
            res[0] = suffix[1];
            res[n - 1] = prefix[n - 2];
            for (int i = 1; i < n - 1; ++i) {
                res[i] = prefix[i - 1] * suffix[i + 1];
            }
            return res;
        }
        */
};