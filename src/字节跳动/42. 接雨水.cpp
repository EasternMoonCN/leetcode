#include "../utils/common.cpp"

/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 */
class Solution {
public:
    /**
     * 对于下标 i，下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值，
     * 下标 i 处能接的雨水量等于下标 i 处的水能到达的最大高度减去 height[i]。
     */
    int trap2(vector<int>& height) {
        int result = 0, n = height.size();
        // 遍历每一个位置i，向i左右分别查找最大值
        for (int i = 1; i < n - 1; ++i) {
            int leftMax = 0, rightMax = 0;
            for (int j = 0; j < i; ++j) {
                leftMax = max(leftMax, height[j]);
            }
            for (int j = i + 1; j < n; ++j) {
                rightMax = max(rightMax, height[j]);
            }
            result += min(leftMax, rightMax) > height[i] ? min(leftMax, rightMax) - height[i] : 0;
        }
        return result;
    }

    int trap3(vector<int>& height) {
        int result = 0, n = height.size();
        vector<int> leftMaxs(n, 0), rightMaxs(n, 0);
        // 分别求取位置i左边最大值，右边最大值
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                leftMaxs[i] = height[i];
            } else {
                leftMaxs[i] = max(leftMaxs[i - 1], height[i]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                rightMaxs[i] = height[i];
            } else {
                rightMaxs[i] = max(rightMaxs[i + 1], height[i]);
            }
        }

        for (int i = 1; i < n - 1; ++i) {
            result += max(min(leftMaxs[i - 1], rightMaxs[i + 1]) - height[i], 0);
        }
        return result;
    }


    int trap(vector<int>& height) {
        int left = 1, right = height.size() - 2;
        int leftMax = height[0], rightMax = height[right + 1];
        int result = 0;
        while (left <= right) {
            if (leftMax < rightMax) {
                result += min(leftMax - height[left], 0);
                leftMax = max(leftMax, height[leftMax++]);
            } else {
                result += min(rightMax - height[right], 0);
                rightMax = max(rightMax, height[rightMax--]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> height = {4,2,0,3,2,5};
    cout << Solution().trap(height) << endl;
}