#include "utils/head.h"

/*
189. 轮转数组
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 1; i <= k; ++i) {
            int temp =nums[n - 1];
            nums.erase(nums.end() - 1);
            nums.insert(nums.begin(), temp);
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(nums, 3);
}