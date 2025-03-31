#include "utils/common.cpp"

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // 大顶堆，利润越大，排序越靠前
        auto cmp = [](const int& pa, const int& pb){
            return pa < pb;
        };
        vector<pair<int, int>> pc;
        int n = capital.size();
        for (int i = 0; i < n; ++i) {
            pc.push_back(make_pair(capital[i], profits[i]));
        }
        // 按所需资本从小到大排序
        sort(pc.begin(), pc.end());
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        // 记录当前索引
        int cur = 0;
        while(k-- > 0) {
            // 将当前资本所足够的入堆
            while (cur < n && pc[cur].first <= w)
            {
                pq.push(pc[cur++].second);
            }

            // 获取第k个项目时最大利润
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};