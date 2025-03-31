#include "../utils/common.h"

class Solution {
public:
    // O(n)
    // O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int s = numbers[left] + numbers[right];
            if (s == target) {
                return {left + 1, right + 1};
            } else if (s < target) {
                left++;
            } else {
                right--;
            }
        }
        return {left, right};
    }
};

