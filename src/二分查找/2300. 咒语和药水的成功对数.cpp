#include "../utils/common.h"

// class Solution {
// public:
//     int lower_bound(vector<int>& nums, long long target) {
//         int left = 0, right = nums.size() - 1;
//         int mid;
//         while (left <= right) {
//             mid = left + ((right - left ) >> 1);
//             if (nums[mid] < target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         return left;
//     }
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n = spells.size(), m = potions.size();
//         sort(potions.begin(), potions.end());
//         vector<int> pairs(n, 0);
//         for (int i = 0; i < n; ++i) {
//             // long long target = success % spells[i] ? success / spells[i] + 1 : success / spells[i];
//             long long target = (success + spells[i] - 1) / spells[i];
//             pairs[i] = m - lower_bound(potions, target);
//         }
//         return pairs;
//     }
// };

class Solution {
public:
    // O(nlog(m))
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        // 红色：target左边
        // 蓝色：target 或 其右边
        auto lower_bound = [](vector<int>& potions, long long target) -> int{
            int left = 0, right = potions.size()- 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (potions[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return left;
        };
        vector<int> res;
        for (int spell : spells) {
            // 寻找 success/spell 上界  
            int pos = lower_bound(potions, (success + spell - 1) / spell);
            res.push_back(potions.size() - pos);
        }
        return res;
    }
};