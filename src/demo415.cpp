#include "utils/common.cpp"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();

        string ans = "";
        int over = 0;
        for (int i = 1; i <= max(n, m); ++i) {
            int c1 = i <= n ? num1[n - i] - '0' : 0;
            int c2 = i <= m ? num2[m - i] - '0' : 0;
            int sum = c1 + c2 + over;
            over = sum / 10;
            ans = to_string(sum % 10) + ans;
        }

        if (over) {
            ans = to_string(over) + ans;
        }
        
        return ans;
    }
};