//
// Created by EasternMoon on 2024/6/25.
//

#include "utils/head.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};