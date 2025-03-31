#include "utils/common.h"

/**
 * 数组A中给定可以使用的1~9的数，返回由A数组中的元素组成的小于n的最大数。
 */

class Solution {
    int maxLen;
    public:
    int largestNumber(vector<int> nums, int target) {
        string nums_s = to_string(target);
        maxLen = nums_s.size() - 1;

        int v = nums_s[0] - '0';
        for (int num : nums) {
            if (v > num) {
                maxLen += 1;
            }
        }
        
        return backTrack(nums, target, 0, 0);
    }

    int backTrack(vector<int> nums, int target, int len, int res) {

         if (res >= target) {
            return 0;
        }
        if (maxLen == len) {
            return res;
        }
       
        int maxRes = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxRes = max(maxRes, backTrack(nums, target,  len + 1, res * 10 + nums[i]));
        }
        return maxRes;
    }
};

int main () {
    Solution s;
    cout << s.largestNumber({1, 2, 5, 9}, 1111) << endl;
    cout << s.largestNumber({1, 2, 4, 9}, 2533) << endl;
    cout << s.largestNumber({1, 2, 5, 9}, 1000) << endl;

    cout << int(log10(abs(1111))) + 1 << endl;
}