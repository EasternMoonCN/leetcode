class Solution {
    public:
    
        // 统计每个字符出现次数，按照出现次数从少到多排序，先删除出现少的字符
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
                return a.second > b.second;
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
            sort(arr.begin(), arr.end());
    
            int n = arr.size(), start = 0, num = arr[0];
            for (int i = 1; i < arr.size(); ++i) {
                if (arr[i] == num) {
                    
                } else {
                    pq.push({num, i - start});
                    num = arr[i];
                    start = i;
                }
            }
            pq.push({num, n - start});
    
            // 够不够删
            while (k >= pq.top().second) {
                auto e = pq.top();
                pq.pop();
                k -= e.second;
            }
            return pq.size();
        }
    };