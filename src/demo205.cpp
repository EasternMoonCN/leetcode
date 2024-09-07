//
// Created by EasternMoon on 2024/6/24.
//
#include "utils/head.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_t_map;
        unordered_map<char, char> t_s_map;
        for(int i = 0; i < s.size(); ++i) {
            if(s_t_map[s[i]] == 0 && t_s_map[t[i]] == 0) {
                s_t_map[s[i]] = t[i];
                t_s_map[t[i]] = s[i];
            } else if (s_t_map[s[i]] && t_s_map[t[i]]) {
                if(s_t_map[s[i]] != t[i] || t_s_map[t[i]] != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
