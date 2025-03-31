#include "../utils/common.cpp"

class Solution {
public:
    unordered_map<char, char> umap = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };
    bool isValid(string s) {
        stack<char> symbol;
        for(int i = 0; i < s.size(); ++i) {
            auto it = umap.find(s[i]);
            if (it == umap.end()) {
                symbol.push(s[i]);
            } else {
                if (symbol.empty()) {
                    return false;
                }
                char c = symbol.top();symbol.pop();
                if (c != umap[s[i]]) {
                    return false;
                }
            }
        }
        return symbol.empty();
    }
};