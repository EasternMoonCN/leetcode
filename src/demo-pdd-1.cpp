#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
62 进制加法
0-9：  0  -  9
A-Z： 10 - （35）10+26
a-z： 36 - （61）36+26
*/

class Solution {
    public:
    string plus(string s1, string s2) {
        int n = padding(s1, s2);
        // 进位值
        int over = 0, temp_int;
        string s3;
        char temp_char;
        for(int i = n - 1; i >= 0; --i) {
            temp_int = toInt(s1[i]) + toInt(s2[i]) + over;
            s3 = toChar(temp_int % 62) + s3;
            // 存在进位
            if(temp_int >= 62) {
                over = temp_int / 62;
            } else if (i != 0){
                over = 0;
            }
        }
        if(over != 0) {
            s3 = toChar(over) + s3;
        }
        return s3;
    }
    /**
     * 填充s1,s2到相同长度
    */
    int padding(string& s1, string& s2) {
        int n1 = s1.length(), n2 = s2.length();
        int n = max(n1, n2);
        if (n1 < n) {
            s1 = string(n - n1, '0') + s1;
        } else {
            s2 = string(n - n2, '0') + s2;
        }
        return n;
    }
    
    /**
     * 将62进制字符c转化为10进制
    */
    int toInt(char c) {
        if(c >= 'a') {
            return c - 'a' + 36;
        } else if (c >= 'A') {
            return c - 'A' + 10;
        }
        return c - '0';
    }

    /**
     * 将0-61映射到62进制字符
    */
    char toChar(int i) {
        if (i >= 36)
        {
            return 'a' + i - 36;
        } else if (i >= 10) {
            return 'A' + i - 10;
        } 
        return '0' + i;

    }
};

int main() {
    // b
    cout << Solution().plus("a", "1") << endl;
    // 10
    cout << Solution().plus("z", "1") << endl;
    //
    cout << Solution().plus("aaa", "bb") << endl;
}