#include "utils/common.cpp"


class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n = num1.size(), m = num2.size();
        
        vector<string> results;
        for (int i = n - 1; i >= 0; --i) {
            string ans;
            int over = 0;
            int c1 = num1[i] - '0';
            for (int j = m - 1; j >= 0; --j) {
                int c2 = num2[j] - '0';
                int sum = c1 * c2 + over;
                ans = to_string(sum % 10) + ans;
                over = sum / 10;
            }
            if (over) {
                ans = to_string(over) + ans;
            }
            results.push_back(ans + string(n - 1 - i, '0'));
        }

        string ans = results[0];
        for (int i = 1; i < results.size(); ++i) {
            ans = addStrings(ans, results[i]);
        } 
        return ans;
    }

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

int main() {
    cout << Solution().multiply("123", "456") << endl;
}