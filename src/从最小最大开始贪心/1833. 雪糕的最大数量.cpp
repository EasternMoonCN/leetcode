class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            int n = costs.size();
            sort(costs.begin(), costs.end());
            int i = 0;
            // 当前剩余硬币能买下第i根雪糕
            while (i < n && coins >= costs[i]) {
                coins -= costs[i++];
            }
            return i;
        }
    };