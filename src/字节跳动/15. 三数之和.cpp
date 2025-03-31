#include "../utils/common.cpp"

/**
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。





示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> results;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }

                if (right < n - 1 && nums[right] == nums[right + 1]) {
                    right--;
                    continue;
                }
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    results.push_back({nums[i], nums[left++], nums[right--]});
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return results;
    }

    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        vector<vector<int>> results;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTrack(nums, {}, results, 0, visited);
        return results;
    }

    void backTrack(vector<int> &nums, vector<int> result, vector<vector<int>> &results, int index, vector<bool> visited)
    {
        if (result.size() == 3)
        {
            if (accumulate(result.begin(), result.end(), 0) == 0)
            {
                results.push_back(result);
            }
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
            {
                continue;
            }
            result.push_back(nums[i]);
            visited[i] = true;
            backTrack(nums, result, results, i + 1, visited);
            visited[i] = false;
            result.pop_back();
        }
    }
};