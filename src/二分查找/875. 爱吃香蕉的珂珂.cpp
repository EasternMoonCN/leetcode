#include "../utils/common.h"
class Solution {
public:
    // 答案范围[0, max(piles)]
    // left - 1：以mid速度可以吃完
    // right + 1
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](int k) -> bool {
            int sum = 0;
            for (int p : piles) {
                sum += (p + k - 1) / k;
                if (sum > h) {
                    return false;
                }
            }
            return true;
        };



        sort(piles.begin(), piles.end());
        int n = piles.size();
        int left = 1, right = piles[n - 1];
        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            // auto it = lower_bound(piles.begin(), piles.end(), mid);
            // // 如果以mid速度，它及其左边每个需要一小时，右边每个需要两小时
            // if (it - piles.begin() + 2 * (piles.end() - it) <= h) {
            //     right = mid - 1;
            // } else {
            //     left = mid + 1;
            // }


            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};