#include "../utils/common.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int a = 0; a < n - 3; ++a) {
            if ((long long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) {
                break;
            }
            if ((long long)nums[a] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
                continue;
            }
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (int b = a + 1; b < n - 2; ++b) {
                if ((long long)nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) {
                    break;
                }
                if ((long long)nums[a] + nums[n - 1] + nums[n - 2] + nums[b] < target) {
                continue;
            }
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                int c = b + 1, d = n - 1;
                while (c < d) {
                    // if (nums[a] + nums[b] + nums[c] > target) {
                    //     break;
                    // }
                    if (c > b + 1 && nums[c] == nums[c - 1]) {
                        c++;
                        continue;
                    }
                    if (d < n - 1 && nums[d] == nums[d + 1]) {
                        d--;
                        continue;
                    }

                    long long t = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (t < target) {
                        c++;
                    } else if (t > target) {
                        d--;
                    } else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};