#include "../utils/common.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; ++i) {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }
                if (right < n - 1 && nums[right] == nums[right + 1]) {
                    right--;
                    continue;
                }

                int s = nums[i] + nums[left] + nums[right];
                if (s == 0) {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                } else if (s < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};