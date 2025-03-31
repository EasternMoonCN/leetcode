#include "../utils/common.h"

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&](int k) -> bool {
            int trip = 0;
            for (int t : time) {
                trip += k / t;
                if (trip >= totalTrips) {
                    return true;
                }
            }
            return false;
        };

        int min_val = *min_element(time.begin(), time.end());
        int max_val = *max_element(time.begin(), time.end());

        // 循环不变量：check(left - 1) 恒为false，check(left)恒为true
        long long left = min_val;
        long long right = (long long) min_val * totalTrips;
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> time = {10000};
    int totalTrips = 10000000;
    cout << Solution().minimumTime(time, totalTrips) << endl;
}