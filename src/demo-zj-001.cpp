#include "utils/head.h"
/*
中文字符串 转 数字，输入金额一亿以内
五百三十万六千零三 -> 5306003
*/

class Solution
{

    int stringToNumber(string s)
    {
        unordered_map<char, int> unit_map = {
            {'零', 0}, {'一', 1}, {'二', 2}, {'三', 3}, {'四', 4}, {'五', 5}, {'六', 6}, {'七', 7}, {'八', 8}, {'九', 9}, 
            {'十', 10}, {'百', 100}, {'千', 1000}, {'万', 1000}};
        int res = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            
        }
        return res;
    }
};