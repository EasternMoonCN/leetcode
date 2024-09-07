//
// Created by EasternMoon on 2024/6/28.
//
#include "utils/head.h"


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        vector<vector<int> > results;
        int i = 0;
        while (i < intervals.size()) {
            vector<int> result;
            result.push_back(intervals[i][0]);
            int maxSecond = intervals[i][1];
            while(i < intervals.size()) {
                if (maxSecond >= intervals[i][0]) {
                    maxSecond = max(maxSecond, intervals[i++][1]);
                } else {
                    break;
                }
            }
            result.push_back(maxSecond);
            results.push_back(result);
        }
        return results;
    }
};
