#include "utils/head.h"
/*
27. 移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
*/

class Solution
{
public:
    // left指向下一个有效元素插入位置，right遍历所有元素
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            // 将有效元素前移
            if (nums[right] != val)
            {
                swap(nums[left++], nums[right++]);
            } else {
                right++;
            }
            
            
        }
        return left;
        
    }

    /*
        // 将待删除元素移到最后，start指向当前遍历元素，end指向最后一个有效元素
        int removeElement(vector<int>& nums, int val) {
            int start = 0, n = nums.size(), end = n - 1;
            // 遍历start-end
            while (start <= end) {
                // 找到待删除元素
                if (nums[start] == val) {
                    // 交换start，end（将删除元素移到最后）
                    swap(nums[start], nums[end]);
                    --end;
                } else {
                    ++start;
                }
            }
            return start;
        }
        */
};