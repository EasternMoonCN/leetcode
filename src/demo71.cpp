//
// Created by EasternMoon on 2024/7/2.
//
#include "utils/head.h"

/*
 始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
 */
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack_str;
        int i = 0, n = path.size();
        while (i < n) {
            // 过滤多余的/
            while (i < n && path[i] == '/') {
                ++i;
            }
            // 处理最后的/
            if (i == n) {
                break;
            }

            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                // 栈非空时才出栈
                if (!stack_str.empty()) {
                    stack_str.pop();
                }
            } else {
                stack_str.push(temp);
            }
        }
        string res = "";
        if (!stack_str.empty()) {
            while (!stack_str.empty()) {
                res = '/' + stack_str.top() + res;
                stack_str.pop();
            }
            return res;
        } else {
            return "/";
        }


    }
};

int main() {
    string s = "/home/user/Documents/../Pictures";
    cout << Solution().simplifyPath(s);
}