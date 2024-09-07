#include "utils/head.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 当前轮次跳跃能达到的最远距离
        int max_far = 0;
        // 当前轮次的边界(有哪些属于当前轮次)
        int end = 0;
        // 跳跃的轮次
        int epoch = 0;
        // nums.size() - 1：不遍历最后一个元素
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            max_far = max(max_far, i + nums[i]);
            // 本轮已跳完，开始下轮需要+1，并更新下一轮边界
            if (i == end)
            {
                end = max_far;
                ++epoch;
            }
        }
        return epoch;
    }
    /*
        int jump(vector<int>& nums) {
            // 要达到下标i，考虑前一个最远的，能够达到i-1的位置
            int n = nums.size() - 1, epoch = 0;
            while (n != 0) {
                // 贪婪的从左往右选一个最远的位置
                bool flag = true;
                for (int i = 0; i < n; ++i) {
                    if (i + nums[i] >= n) {
                        epoch++;
                        n = i;
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return INT_MAX;
                }
            }
            return epoch;
        }
        */
    /*
        int jump(vector<int> &nums)
        {
            return backtrace(nums, 0, 0, nums.size());
        }

        int backtrace(vector<int> nums, int epoch, int index, int n)
        {
            if (index == n - 1)
            {
                return epoch;
            }
            int min_epoch = INT_MAX;
            for (int i = nums[index]; i > 0; --i)
            {
                int temp = backtrace(nums, epoch + 1, index + i, n);
                min_epoch = min(min_epoch, temp);
            }
            return min_epoch;
        }
        */
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().jump(nums);
}