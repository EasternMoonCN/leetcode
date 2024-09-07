#include "utils/head.h"

/*
151. 反转字符串中的单词
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> res_stack;
        string temp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (temp.empty()) {
                    continue;
                }
                res_stack.push(temp);
                temp = "";
            } else {
                temp += s[i];
            }
        }
        if (!temp.empty()) {
            res_stack.push(temp);
        }

        string res_str;
        while (!res_stack.empty()) {
            if (!res_str.empty()) {
                res_str += " ";
            }
            res_str += res_stack.top();
            res_stack.pop();
        }
        return res_str;
    }
};