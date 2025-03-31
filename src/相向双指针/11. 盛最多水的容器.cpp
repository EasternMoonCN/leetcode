#include "../utils/common.h"

class Solution {
public:
    // 时间度杂读o(n)，空间复杂度o(1)
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};