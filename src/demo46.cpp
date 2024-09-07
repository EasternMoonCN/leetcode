//
// Created by EasternMoon on 2024/6/26.
//
#include "utils/head.h"
/*
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > results;
        backtrack(0, nums, results);
        return results;
    }

    void backtrack(int index, vector<int> nums, vector<vector<int> >& results) {
        if (index == nums.size()) {
            results.push_back(nums);
            return;
        }
        // 从第index位开始，与index后面元素交换，包括其子递归（index + 1）
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            backtrack(index + 1, nums, results);
            swap(nums[i], nums[index]);
        }
    }
};
void printData(int data) {
    cout << data << " ";
}

void printResult(vector<int> result) {
    for_each(result.begin(), result.end(), printData);
    cout << endl;
}
int main() {
    vector<int> nums = {1, 2};
    vector<vector<int> > results = Solution().permute(nums);
    for_each(results.begin(), results.end(), printResult);
}