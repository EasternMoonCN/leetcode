#include "utils/head.h"

/*

209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 
子数组
 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, n = nums.size(), sum = 0, res = INT_MAX;
        while(right < n) {
            // 累计[left, right] 和
            sum += nums[right++];
            // 找到一个子串满足
            while(sum >= target) {
                // 求当前子串长度（前面right已自增）
                res = min(res, right - left);
                // left自增：修改开始节点，找到一个不满足的起始节点。即[left, right]满足，则[left + 1, right] 可能满足 或 right + ？ 满足
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;

    }
    /*
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            // 前缀和:前i个和
            vector<int> preSums(n + 1, 0);
            for(int i = 1; i <= n; ++i) {
                preSums[i] = preSums[i - 1] + nums[i - 1];
            }
            int res = INT_MAX;
            for (int i = 1; i <= n; ++i) {
                // 实际是为了去掉前i-1个多影响，从第i个开始计算要多少个
                int preSumTarget = target + preSums[i - 1];
                // 二分查找目标元素或其插入位置
                auto it = lower_bound(preSums.begin(), preSums.end(),
       preSumTarget); if(it != preSums.end()) { res = min(res,
       static_cast<int>(it - preSums.begin() - (i - 1)));
                }
            }
            return res == INT_MAX ? 0 : res;
        }
        */
    /*
        int minSubArrayLen(int target, vector<int>& nums) {
            int minLen = 0, sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                sum = += nums[i];
                if(sum >= target) {
                    minLen = i + 1;
                }
            }

            for(int j = 1; j < nums.size(); ++j)) {
                sum -= nums[j - 1];
            }
            return minLen == nums.size() + 1 ? 0 : minLen;
        }
        */
    /*
        int minSubArrayLen(int target, vector<int>& nums) {
            int minLen = nums.size() + 1;
            for(int i = 0; i < nums.size(); ++i) {
                int sum = 0;
                for(int j = i; j < nums.size(); ++j) {
                    sum += nums[j];
                    if(sum >= target) {
                        minLen = min(minLen, j - i + 1);
                        break;
                    }
                }
            }
            return minLen == nums.size() + 1 ? 0 : minLen;
        }
        */
};