//
// Created by EasternMoon on 2024/7/3.
//

/*
将操作数压入操作数栈；
将运算符压入运算符栈；
忽略左括号；
在遇到右括号时，弹出一个运算符，弹出所需数量的操作数，并将运算符和操作数的运算结果压入操作数栈。


1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式
'+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
'-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
输入中不存在两个连续的操作符
每个数字和运行的计算将适合于一个有符号的 32位 整数
 */

#include "utils/common.h"

class Solution {
private:
    /**
     *    &  +  -  *  /  (  )
     * &
     * +
     * -
     * *
     * /
     * (
     * )
     */
     unordered_map<char, int> symbolIndex = {
            {{'&'}, 0},
            {{'+'}, 1},
            {{'-'}, 2},
            {{'*'}, 3},
            {{'/'}, 4},
            {{'('}, 5},
            {{')'}, 6}
     };
    char symbolTable[7][7] = {
            {'=', '<', '<', '<', '<', '<', ' '},
            {'>', '>', '>', '<', '<', '<', '>'},
            {'>', '>', '>', '<', '<', '<', '>'},
            {'>', '>', '>', '>', '>', '<', '>'},
            {'>', '>', '>', '>', '>', '<', '>'},
            {' ', '<', '<', '<', '<', '<', '='},
            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    unordered_map<char, function<int(int, int)> > calculateMap = {
            {{'+'}, [](int a, int b) { return a + b; }},
            {{'-'}, [](int a, int b) { return a - b; }},
            {{'*'}, [](int a, int b) { return a * b; }},
            {{'/'}, [](int a, int b) { return a / b; }},
    };
    stack<pair<int, int> > numberStack;
    stack<pair<char, int> > symbolStack;
public:
    Solution() {
        symbolStack.emplace('&', -1);
    }
    void processNumber(const string& s, const int& i) {
        int number = s[i] - '0';
        if (!numberStack.empty()) {
            // 处理连续字符情况
            pair<int, int> top = numberStack.top();
            if (top.second == i - 1) {
                number = top.first * 10 + number;
                numberStack.pop();
            }
        }
        numberStack.emplace(number, i);
    }
    void processDigit(const string& s, int& i) {
        pair<char, int> symbolTop = symbolStack.top();
        int firstIndex = symbolIndex[symbolTop.first];
        int secondIndex = symbolIndex[s[i]];
        char symbolType = symbolTable[firstIndex][secondIndex];
        if (symbolType == '<') {
            symbolStack.emplace(s[i], i);
            ++i;
        } else if (symbolType == '>') {
            symbolStack.pop();
            if (symbolTop.first == '-' && symbolTop.second - 1 == symbolStack.top().second) {
                int a = numberStack.top().first; numberStack.pop();
                numberStack.emplace(a * -1, - 1);
            } else {
                int b = numberStack.top().first; numberStack.pop();
                int a = numberStack.top().first; numberStack.pop();
                numberStack.emplace(calculateMap[symbolTop.first](a, b), -1);
            }

        } else if (symbolType == '=') {
            symbolStack.pop();
            ++i;
        }
    }
    int calculate(string s) {
        s += '&';
        int i = 0;
        string scopy = "";
        for (char i : s) {
            if (i != ' ') {
                scopy += i;
            }
        }
        while (i < scopy.length()) {
            if (isdigit(scopy[i])) {
                processNumber(scopy, i++);
            } else {
                processDigit(scopy, i);
            }
        }
        return numberStack.top().first;
    }
};

int main() {
    cout << Solution().calculate("1-(1*-2)");
}