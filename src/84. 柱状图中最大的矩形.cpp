#include "utils/common.cpp"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> is;
        // 从左往右找第一个小于自己的元素
        vector<int> lefts(n), rights(n);
        for (int i = 0; i < n; ++i) {
            while (!is.empty() && heights[is.top()] >= heights[i]) {
                is.pop();
            }
            lefts[i] = is.empty() ? -1 : is.top();
            is.push(i);
        }

        is = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!is.empty() && heights[is.top()] >= heights[i]) {
                is.pop();
            }
            rights[i] = is.empty() ? n : is.top();
            is.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; ++i) {
            area = max(area, heights[i] * (rights[i] - lefts[i] - 1));
        }
        return area;
    }
    
    int largestRectangleArea2(vector<int>& heights) {
        int area = 0, n = heights.size();
        for (int i = 0; i < n; ++i) {
            int width, height = INT_MAX;
            for (int j = i; j < n; ++j) {
                width = (j - i) + 1;
                height = min(height, heights[j]);
                area = max(area, width * height);
            }
        }
        return area;
    }

    int largestRectangleArea3(vector<int>& heights) {
        int n = heights.size(), area = 0;
        // 高度height[i] 的最大面积
        for (int i = 0; i < n; ++i) {
            int left = i, right = i;
            // 找到高度小于i的
            while (left - 1 >= 0 && heights[left - 1] >= heights[i]) {
                --left;
            }

            while (right + 1 < n && heights[right + 1] >= heights[i]) {
                ++right;
            }
            area = max(area, (right - left + 1) * heights[i]);
        }
        return area;
    }
};

int main() {
    vector<int> heights = {0, 9};
    cout << Solution().largestRectangleArea(heights);
}