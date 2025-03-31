
/**
https://leetcode.cn/discuss/post/3091107/fen-xiang-gun-ti-dan-tan-xin-ji-ben-tan-k58yb/
*/
class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            int n = nums.size();
            // 优先翻转最小的负数
            sort(nums.begin(), nums.end());
    
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                // 存在负数且还能反转的情况下进行反转
                if (nums[i] < 0 && k > 0) {
                    // 优先将最大的负数转正
                    nums[i] = -nums[i];
                    k--;
                }
                sum += nums[i];
            }
            // k全部被负数使用，或者存在偶数个负数，可以相互抵消
            if (k == 0 || ((k & 1) == 0)) {
                return sum;
            } else { 
                // k 还存奇数个
                sort(nums.begin(), nums.end());
                // 使用当前最小的数转换，由于前面加过一次，所以要减去2倍
                sum -= 2 * nums[0];
                return sum;
            }
        }
    };