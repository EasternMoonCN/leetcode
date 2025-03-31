#include "utils/common.cpp"


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return (nums1[a.first] + nums2[a.second]) > (nums1[b.first] + nums2[b.second]);
        };
        int n1 = nums1.size(), n2 = nums2.size();

        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, n1); i++)
        {
            pq.push(make_pair(i, 0));
        }

        vector<vector<int>> ans;
        while(k-- > 0 && !pq.empty()) {
            pair<int, int> index = pq.top();
            pq.pop();
            ans.push_back({nums1[index.first], nums2[index.second]});
            if (index.second + 1 < n2) {
                pq.push(make_pair(index.first, index.second + 1));
            }
        }
        return ans;
    };

};

int main() {
    vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};
    vector<vector<int>> res = Solution().kSmallestPairs(nums1, nums2, 3);
    common<int>::printVectors(res);
}