#include "../utils/common.h"

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
    
        auto check = [=](int num) -> bool {
            int cnt = 1, x0 = price[0];
            for (int x : price) {
                if (x >= x0 + num) {
                    x0 = x;
                    cnt++;
                }
            }
            return cnt >= k;
        };
        int left = 1, right = (price.back() - price[0]) / (k - 1);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

int main() {
    vector<int> price = {13,5,1,8,21,2};
    int k = 3;
    cout << Solution().maximumTastiness(price, k);
}