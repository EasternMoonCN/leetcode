class Solution {
    public:
        // O(N^2)
        int bestTeamScore(vector<int>& scores, vector<int>& ages) {
            int n = scores.size();
            vector<pair<int, int>> pairs;
    
    
            for (int i = 0; i < n; ++i) {
                pairs.push_back({ages[i], scores[i]});
            }
            // 需要排序，因为尾巴为i时，前面的只和i比较，i后面的状态不好判断
            sort(pairs.begin(), pairs.end(), [&](pair<int, int> p1, pair<int, int> p2) {
                return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
            });
    
            vector<int> memory(n, -1);
    
            // dfs[i]:尾巴为第i个球员的最大分数
            auto dfs = [&](this auto&& dfs, int i) {
                if (i < 0) {
                    return 0;
                }
                if (memory[i] != -1) {
                    return memory[i];
                }
    
                int score = 0;
                for (int j = 0; j < i; ++j) {
                    if (pairs[j].second <= pairs[i].second) {
                        score = max(score, dfs(j));
                    }
                }
                memory[i] = score + pairs[i].second;
                return memory[i];
            };
            int res = 0;
            for (int i = 0; i < n; ++i) {
                res = max(res, dfs(i));
            }
            return res;
        }
    };