class Solution {
    public:
        int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
            int n = capacity.size();
            vector<int> leftc(n, 0);
            for (int i = 0; i < n; ++i) {
                leftc[i] = capacity[i] - rocks[i];
            }
    
            sort(leftc.begin(), leftc.end());
    
            int i = 0;
            // 当前容量大于背包大小
            while (i < n && additionalRocks >= leftc[i]) {
                // 前面i个背包都装满了
                additionalRocks -= leftc[i++];
            }
            return i;
        }
    };