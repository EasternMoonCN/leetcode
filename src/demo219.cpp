//
// Created by EasternMoon on 2024/6/25.
//
#include "utils/head.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] == nums[j] && j - i <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};