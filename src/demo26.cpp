#include "utils/head.h"
/*
26. 删除有序数组中的重复项

给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。

*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // left:待插入元素位置，right:当前遍历位置
        int left = 1, right = 1;
        while (right < nums.size())
        {
            // 当前遍历位置，和前一个元素比较
            if (nums[right] != nums[right - 1])
            {
                nums[left++] = nums[right++];
            }
            else
            {
                right++;
            }
        }
        return left;
    }
    /*
        int removeDuplicates(vector<int> &nums)
        {
            // left:待插入元素位置，right:当前遍历位置
            int left = 1, right = 1;
            while (right < nums.size())
            {
                // 当前遍历位置，和最后一个有效元素比较
                if (nums[right] != nums[left - 1])
                {
                    swap(nums[left++], nums[right++]);
                }
                else
                {
                    right++;
                }
            }
            return left;
        }
        */
};
int main() {
    vector<int> nums = {1, 1, 2};
    cout << Solution().removeDuplicates(nums);
}