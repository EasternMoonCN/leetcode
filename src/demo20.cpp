#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 != 0)
        {
            return false;
        }
        
        stack<char> stk;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (int i = 0; i < n; i++)
        {
            // 判断map中是否存在键
            if (pairs.count(s[i]))
            {
                if (stk.empty() || stk.top() != pairs[s[i]])
                {
                    return false;
                }
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
        
    }
};

int main() {
    cout << Solution().isValid("()");
}