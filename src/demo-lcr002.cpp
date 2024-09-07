#include <string>
#include <iostream>
using namespace std;
/**
给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。
*/
class Solution {
public:

    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int nm = max(n, m);
        // 填充到最大长度
        if (n < nm) {
            string padding(nm - n, '0');
            a = padding + a;
        } else {
            string padding(nm - m, '0');
            b = padding + b;
        }
        string res;
        // over:是否存在进位，第i位temp计算结果
        int over = 0;
        char temp;
        for (int i = nm - 1; i >= 0; --i) {
            temp = a[i] + b[i] - '0' + over;
            // 结果是否需要进位
            if(temp > '1') {
                temp -= 2;
                over = 1;
            } else if (i != 0)
            {
                over = 0;
            }
            
            res = temp + res;
        }
        // 最后是否还存在进位
        if(over == 1) {
            res = '1' + res;
        }
        return res;
    }
};

int main() {
    cout << Solution().addBinary("10", "11");
}