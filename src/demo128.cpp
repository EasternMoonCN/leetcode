//
// Created by EasternMoon on 2024/6/25.
//

#include "utils/head.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int num : nums) {
            numSet.insert(num);
        }
        int maxLongest = 0;

        for(int num : numSet) {
            // 不存在num-1时，说明num是首字符。存在num-1时，无需计算此字符开始的长度
            if(!numSet.count(num - 1)) {
                int longest = 1;
                while(numSet.count(++num)) {
                    ++longest;
                }
                maxLongest = max(longest, maxLongest);
            }

        }
        return maxLongest;
    }
};
