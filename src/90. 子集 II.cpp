#include "utils/common.cpp"

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int len = 0; len <= n; ++len)
        {
            vector<vector<int>> temp;
            vector<bool> visited(n, false);
            backTrack(nums, {}, temp, 0, len, visited);
            results.insert(results.end(), temp.begin(), temp.end());
        }
        return results;
    }

    void backTrack(vector<int> nums, vector<int> result, vector<vector<int>> &results, int start, int len, vector<bool> visited)
    {
        if (result.size() == len)
        {
            results.push_back(result);
            return;
        }
        for (int i = start; i < nums.size(); ++i)
        {
            if (result.size() + 1 > len)
            {
                break;
            }
            // 与前一个元素相同，但是前一个元素没有被访问
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
            {
                continue;
            }
            result.push_back(nums[i]);
            visited[i] = true;
            backTrack(nums, result, results, i + 1, len, visited);
            visited[i] = false;
            result.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<bool> visited(n, false);
        backTrack2(nums, {}, results, 0, visited);
        return results;
    }

    void backTrack2(vector<int> nums, vector<int> result,
                    vector<vector<int>> &results, int start,
                    vector<bool> visited)
    {
        if (start == nums.size())
        {
            results.push_back(result);
            return;
        }
        if (start > 0 && nums[start] == nums[start - 1] && !visited[start - 1])
        {
            backTrack2(nums, result, results, start + 1, visited);
        }
        else
        {
            result.push_back(nums[start]);
            visited[start] = true;
            backTrack2(nums, result, results, start + 1, visited);
            visited[start] = false;
            result.pop_back();
            backTrack2(nums, result, results, start + 1, visited);
        }
    }

    vector<vector<int>> subsetsWithDup3(vector<int>& nums) {
        int n = nums.size(), m = 1 << n;
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < m; ++i) {
            vector<int> result;
            vector<bool> visited(n, false);
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    if (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) {
                        flag = false;
                        break;
                    }
                    visited[j] = true;
                    result.push_back(nums[j]);
                }
            }
            if (flag) {
                results.push_back(result);
            }
        }
        return results;
    }
};