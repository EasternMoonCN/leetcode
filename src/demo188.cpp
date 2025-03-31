#include "utils/common.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> b(k, -prices[0]);
        vector<int> s(k, 0);
        for (int i = 0; i < n; ++i) {
            b[0] = max(b[0], -prices[i]);
            s[0] = max(s[0], b[0] + prices[i]);
            for (int j = 1; j < k; ++j) {
                b[j] = max(b[j], s[j - 1] - prices[i]);
                s[j] = max(s[j], b[j] + prices[i]);
            }
        }
        return s[k - 1];
    }
};