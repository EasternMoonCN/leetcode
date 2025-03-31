#include "utils/common.cpp"

class Solution {
public:
    vector<int> nextGreaterElements2(vector<int>& nums) {
        int b = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end() - 1);
        int n = nums.size();
        vector<int> result(n);
        stack<int> is;
        for (int i = n - 1; i >= 0; --i) {
            while (!is.empty() && is.top() <= nums[i]) {
                is.pop();
            }
            result[i] = is.empty() ? -1 : is.top();
            is.push(nums[i]);
        }
        result.erase(result.begin() + b, result.end());
        return result;
    }

    vector<int> nextGreaterElements2(vector<int>& nums) {
        int b = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end() - 1);
        int n = nums.size();
        vector<int> result(n);
        stack<int> is;
        for (int i = n - 1; i >= 0; --i) {
            while (!is.empty() && is.top() <= nums[i]) {
                is.pop();
            }
            result[i] = is.empty() ? -1 : is.top();
            is.push(nums[i]);
        }
        result.erase(result.begin() + b, result.end());
        return result;
    }
};