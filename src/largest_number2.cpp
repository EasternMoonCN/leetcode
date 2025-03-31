#include "utils/common.cpp"

class Solution {
public:
    int largestNumber2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), greater<int>());
        return backTrack(nums, target, 0, INT_MIN);
    }

private:
    int backTrack(vector<int>& nums, int remainingTarget, int currentIndex, int maxVal) {
        if (remainingTarget == 0) {
            // 当前组合正好等于目标值
            return maxVal;
        } else if (currentIndex >= nums.size() || remainingTarget < 0) {
            // 超过数组边界或者剩余目标值小于0，说明当前组合无效
            return maxVal;
        }
        
        // 不使用当前数字
        int resultWithoutCurrent = backTrack(nums, remainingTarget, currentIndex + 1, maxVal);
        
        // 使用当前数字
        int resultWithCurrent = (remainingTarget >= nums[currentIndex]) ?
                                backTrack(nums, remainingTarget - nums[currentIndex], currentIndex, 
                                          max(10 * resultWithoutCurrent + nums[currentIndex], maxVal)) :
                                resultWithoutCurrent;
        
        return resultWithCurrent;
    }
};

int main () {
    vector<int> nums = {1, 2, 5, 9};
    Solution s;
    // cout << s.largestNumber2(nums, 1111) << endl;
    cout << s.largestNumber2(nums, 2533) << endl;
    // cout << s.largestNumber2({1, 2, 5, 9}, 1000);
}