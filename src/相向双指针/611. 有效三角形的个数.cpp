#include "../utils/common.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), res = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // 任何i属于[i, j - 1] 和j相加都满足大于k
                    res += j - i;
                    j--;
                } else {
                    //i和任何j属于[i+1, j] 相加都满足小于等于k
                    i++;
                }
            }
        }
        return res;
    }
};