//
// Created by EasternMoon on 2024/6/24.
//

#include "utils/head.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> wordMap;
        unordered_map<char, string> patternMap;
        int start = 0, j = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                string word = s.substr(start, i - start);
                if ((wordMap[word] && wordMap[word] != pattern[j]) ||
                    (patternMap[pattern[j]] != "" && patternMap[pattern[j]] != word)) {
                    return false;
                }
                wordMap[word] = pattern[j];
                patternMap[pattern[j]] = word;
                ++j;
                start = i + 1;
            }
        }
        return j == pattern.size();
    }
};