class Solution {
    public:
        /**
        *如果窗口中有 c 个元素 x，再进来一个 x，会新增 c 个相等数对。（新进数组和前面每个x都可以构成好数对）
        *如果窗口中有 c 个元素 x，再去掉一个 x，会减少 c−1 个相等数对。（最早移除x，和后面每个x都要移除一次好数对）
        */
        long long countGood(vector<int>& nums, int k) {
            // 感觉像是滑动窗口，窗口内是恰好不满足k对好数组的下标（和以往滑动算法有所区别）
            unordered_map<int, int> cnt;
            long long res = 0;
            int n = nums.size();
            int left = 0, pairs = 0;
    
            for (int right = 0; right < n; ++right) {
                int x = nums[right];
                // 窗口内有cnt[x]个数 和 将要移入对x相同，先增加，再移入窗口
                pairs += cnt[x]++;
                // 达到k个好数对
                while (pairs >= k) {
                    pairs -= --cnt[nums[left++]];
                }
                // [left,right]不满足要求，但是[left-1, right]是满足要求的
                // 由于子数组越长，约满足要求，所以[0, right] 都是满足要求的
                // 即在固定right后，左端点[0, left-1]都满足要求
                res += left;
            }
            return res;
        }
    };