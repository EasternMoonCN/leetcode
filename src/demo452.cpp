//
// Created by EasternMoon on 2024/7/2.
//

#include "utils/common.cpp"


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> p1, vector<int> p2){return p1[0] < p2[0];});
        int left = points[0][0], right = points[0][1], res = 1;
        for (auto point : points) {
            // 只要再范围内，更新本次范围
            if(point[0] <= right) {
                left = max(left, point[0]);
                right = min(right, point[1]);
            } else {
                res++;
                left = point[0];
                right = point[1];
            }
        }
        return res;
    }
};

int main() {
//    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
//    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
            cout << Solution().findMinArrowShots(points);
}