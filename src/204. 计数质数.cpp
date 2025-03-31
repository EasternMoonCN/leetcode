#include "utils/common.h"

class Solution {
public:
    // 对于每个素数，将其倍数标记为false
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> nums(n, true);
        for (int i = 2; i * i < n; ++i) {
            if (nums[i]) {
                // 如果nums[i]为素质，则i 的所有倍数j的值nums[j]都非素数
                for (int j = i * i; j < n; j+=i ) {
                    nums[j] = false;
                }
            }
        }
        return accumulate(nums.begin() + 2, nums.end(), 0);
    }
};