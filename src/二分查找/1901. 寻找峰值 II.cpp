#include "../utils/common.cpp"
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // int n = mat.size(), m = mat[0].size();
        // for (int i = 0; i < m; ++i) {
        //     int left = 0, right = n - 2;
        //     while (left <= right) {
        //         int mid = left + ((right - left) >> 1);
        //         if (mat[mid][i] < mat[mid + 1][i]) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     }
        //     if ((i == 0 || mat[left][i - 1] < mat[left][i]) && (i == m - 1 || mat[left][i] > mat[left][i + 1])) {
        //         return {left, i};
        //     }
        // }
        // return {-1, -1};

        // int n = mat.size(), m = mat[0].size();
        // for (int i = 0; i < n; ++i) {
        //     int left = 0, right = m - 2;
        //     while (left <= right) {
        //         int mid = left + ((right - left) >> 1);
        //         if (mat[i][mid] < mat[i][mid + 1]) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     }

        //     if ((i == 0 || mat[i - 1][left] < mat[i][left]) && (i == n - 1 || mat[i][left] > mat[i + 1][left])) {
        //         return {i, left};
        //     }
        // }
        // return {-1, -1};

        int n = mat.size();
        int left = 0, right = n - 2;

        auto indexOfMax = [&](int i) -> int {
            return max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
        };
        while (left <= right) {
            int i = left + ((right - left) >> 1);
            // 第i行最大元素下标
            int j = indexOfMax(i);
            if (mat[i][j] < mat[i + 1][j]) {
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return {left, indexOfMax(left)};
    }
};

int main() {
    vector<vector<int>> mat = {{70,50,40,30,20},{100,1,2,3,4}};
    common<int>::printVector(Solution().findPeakGrid(mat));
    return 0;
}