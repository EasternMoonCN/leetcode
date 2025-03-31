#include "../utils/common.cpp"

/**
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

 

示例 1：

输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：

输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
 */
class Solution {
public:
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), result = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0, n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; ++i) {
            int k = 0, len = min(n - i, m);
            for (int j = 0; j < len; ++j) {
                if(nums1[i + j] == nums2[j]) {
                    ++k;
                } else {
                    k = 0;
                }
                result = max(result, k);
            }
            
        }

        for (int j = 0; j < m; ++j) {
            int k = 0, len = min(m - j, n);
            for (int i = 0; i < len; ++i) {
                if (nums2[i + j] == nums1[i]) {
                    ++k;
                } else {
                    k = 0;
                }
                result = max(result, k);
            }
            
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1,1,0,0,1}, nums2 = {1, 1, 0, 0, 0};
    cout << Solution().findLength( nums1, nums2);
}