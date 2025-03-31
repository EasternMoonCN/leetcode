#include "../utils/common.cpp"
/**
 * 有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。
 * 出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。
 * 已知马戏团每个人的身高和体重，请编写代码计算叠罗汉最多能叠几个人。

示例：
输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
输出：6
解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
提示：

height.length == weight.length <= 10000
 */
class Solution {
public:
    // int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
    //     vector<pair<int, int>> hw;
    //     int n = height.size();
    //     for (int i = 0; i < n; ++i) {
    //         hw.push_back(make_pair(height[i], weight[i]));
    //     }

    //     // 从小到大排序
    //     sort(hw.begin(), hw.end(), [](pair<int, int> a, pair<int, int> b) {
    //         return a.first != b.first ? a.first < b.first : a.second < b.second; 
    //     });

    //     int left = 0, right = 1;
    //     int maxNum = 1;
    //     while (right < n) {
    //         while (left < right && (hw[right - 1].first >= hw[right].first || hw[right - 1].second >= hw[right].second)) {
    //             left++;
    //         }
    //         ++right;
    //         maxNum = max(maxNum, right - left);
    //     }
    //     return maxNum;
    // }
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int, int>> hw;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            hw.push_back(make_pair(height[i], weight[i]));
        }

        // 一维从小到大，二维从大到小排序（避免一维相同）
        sort(hw.begin(), hw.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first != b.first ? a.first < b.first : a.second > b.second; 
        });

        // 最长递增子序列
        vector<int> dp(n, 1);
        int result = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (hw[i].second > hw[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;

    }
};

int main() {
    vector<int> height = {2868,5485,1356,1306,6017,8941,7535,4941,6331,6181};
    vector<int> weigh = {5042,3995,7985,1651,5991,7036,9391,428,7561,8594};
    cout << Solution().bestSeqAtIndex(height, weigh);
}