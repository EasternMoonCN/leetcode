//
// Created by EasternMoon on 2024/7/3.
//

#include "utils/head.h"

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        unordered_map<string, function<int(int, int)>> map = {
                {"+", [](int a, int b) { return a + b; }},
                {"-", [](int a, int b) { return a - b; }},
                {"*", [](int a, int b) { return a * b; }},
                {"/", [](int a, int b) { return a / b; }},
        };
        stack<int> operatorStack;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int o1 = operatorStack.top();
                operatorStack.pop();
                int o2 = operatorStack.top();
                operatorStack.pop();
//                int res = 0;
//                if(tokens[i] == "+") {
//                    res = o1 + o2;
//                } else if(tokens[i] == "-") {
//                    res = o1 - o2;
//                } else if(tokens[i] == "*") {
//                    res = o1 * o2;
//                } else {
//                    res = o1 / o2;
//                }
//                operatorStack.push(res);
                operatorStack.push(map[tokens[i]](o1, o2));
            } else {
                operatorStack.push(stoi(tokens[i]));
            }
        }
        return operatorStack.top();
    }
};