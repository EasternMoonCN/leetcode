#include "../utils/common.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left <= right) {
            // h系数
            int mid = (left + right ) / 2;
            auto pos = lower_bound(citations.begin(), citations.end(), mid);
            // 小于h系数引用次数的论文数量
            if (citations.end() - pos < mid) {
                // left = mid + 1; 
                right = mid - 1;
            } else {
                // right = mid - 1;
                left = mid + 1;
            }
        }
        return right;
    }
};