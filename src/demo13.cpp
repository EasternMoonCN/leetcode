#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && map[s[i]] < map[s[i + 1]])
            {
                res -= map[s[i]];
            } else {
                res += map[s[i]];
            }
            
        }
        return res;
    }
};

int main() {
    cout << Solution().romanToInt("MCMXCIV");
}