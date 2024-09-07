//
// Created by EasternMoon on 2024/7/1.
//
#include "utils/common.cpp"

/*
给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。

在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。

返回插入之后的 intervals。

注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>> results;
        if (n == 0) {
            results.push_back({newInterval[0], newInterval[1]});
            return results;
        }
        if (intervals[i][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), {newInterval[0], newInterval[1]});
            return intervals;
        }
        // 找到第一个尾数大于待插入元素头数：前面的元素可以直接插入
        while (i < n && intervals[i][1] < newInterval[0]) {
            results.push_back({intervals[i][0], intervals[i][1]});
            ++i;
        }
        int first = newInterval[0], second = newInterval[1];
        if (i < n && newInterval[1] >= intervals[i][0]) {
            // 待插入元素起始值
            first = min(intervals[i][0], newInterval[0]);
            second = max(intervals[i][1], newInterval[1]);
        }

        // 找到一个插入合并的结束位置：中间元素需合并
        while (i < n && intervals[i][0] <= newInterval[1]) {
            second = max(intervals[i++][1], second);
        }
        // 插入元素：合并段的最小值，最大值
        results.push_back({first, second});
        // 插入剩下元素
        while (i < n) {
            results.push_back({intervals[i][0], intervals[i][1]});
            ++i;
        }
        return results;
    }
};

int main() {
//    vector<vector<int> > intervals = {{1, 3}, {6, 9}};
//    vector<int> newInterval = {2, 5};
    vector<vector<int> > intervals = {{1, 5}};
    vector<int> newInterval = {6, 8};
    vector<vector<int> > results = Solution().insert(intervals, newInterval);
    common::printVectors(results);
}