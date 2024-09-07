#include "utils/head.h"

/*
135. 分发糖果
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。


*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> lefts(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                lefts[i] = lefts[i - 1] + 1;
            } else {
                lefts[i] = 1;
            }
        }
        int right = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (j < n- 1 && ratings[j] > ratings[j + 1]) {
                // 需要在右边已有的值上增加
                right ++;
            } else {
                // 否则充值为1
                right = 1;
            }
            res += max(lefts[j], right);
        }
        return res;
    }
};