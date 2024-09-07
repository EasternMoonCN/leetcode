//
// Created by EasternMoon on 2024/6/24.
//
#include "utils/head.h"
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(char c : magazine) {
            ++map[c];
        }
        for(char c : ransomNote) {
            if(map[c] == 0) {
                return false;
            } else {
                --map[c];
            }
        }
        return true;
    }
};

int main() {
    //
    unordered_map<char, int> map_i;
    unordered_map<char, char> map_c;
    unordered_map<char, string> patternMap;
    cout << (int) map_c['a'] << endl;
    cout << patternMap['a'] << endl;

    cout << Solution().canConstruct("aa", "aab");
    return 0;
}
