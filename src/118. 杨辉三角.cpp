#include "utils/common.cpp"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        // 遍历每一层
        for (int i = 0; i < numRows; ++i) {
            // 每一个
            vector<int> nums;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    nums.push_back(1);
                } else {
                    nums.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
                }
            }
            triangle.push_back(nums);
        }
        return triangle;
    }
};