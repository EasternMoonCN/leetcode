//
// Created by EasternMoon on 2024/6/25.
//
#include "utils/head.h"

/*
 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 */
class Solution {
public:
    // 字母异位词，排序后相同
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};