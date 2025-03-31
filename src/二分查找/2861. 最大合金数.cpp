#include "utils/common.h"

/**
 * 制造的合金越多，花的钱越多
 * 制造num份合金，花的钱 <= budget，则小于num份的合金都可以制造
 * 制造num份合金，花的钱 > budget，则大于num份的合金都不可以制造
 */

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

        int res = 0;
        // min(stock) : 已有合金能制造数量 + 每份合金制造所需数量为1，费用为1，在预算为budget情况下能制造最多数量
        // 只加budget是因为stock其他材料存在剩余，可能不需要费用，但至少有一类材料需要费用  
        int max_num = *min_element(stock.begin(), stock.end()) + budget;
        for (auto com : composition) {
            auto check = [&](long long num) -> bool {
                long long total = 0;
                for (int i = 0; i < n; ++i) {
                    if (stock[i] < num * com[i]) {
                        // 已有份数不足情况下，还需要购买num * com[i] - stock[i]
                        total += (num * com[i] - stock[i]) * cost[i];
                        if (total > budget) {
                            return false;
                        }
                    }
                }
                return true;
            };
            int left = 0, right = max_num;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (check(mid)) {   // 能购买mid份情况下，继续判断是否能够购买大于mid份
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            res = max(res, left - 1);
        }
        return res;
    }
};