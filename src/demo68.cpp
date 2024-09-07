#include "utils/head.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        // 每行元素个数，及其对应长度和
        vector<int> rowNums, rowWidths;
        int num = 0, width = 0;
        for (int i = 0; i < n; ++i)
        {
            if (width + num + words[i].size() > maxWidth)
            {
                rowNums.push_back(num);
                rowWidths.push_back(width);
                num = 0;
                width = 0;
            }
            num++;
            width += words[i].size();
        }
        rowNums.push_back(num);
        rowWidths.push_back(width);

        vector<string> res;
        int i = 0, total = 0;
        for (int j = 0; j < rowNums.size() - 1; ++j)
        {
            string s;

            total += rowNums[j];
            int space = rowNums[j] > 1 ? (maxWidth - rowWidths[j]) / (rowNums[j] - 1) : maxWidth - rowWidths[j];
            int k = rowNums[j] > 1 ? (maxWidth - rowWidths[j]) % (rowNums[j] - 1) : 0;
            int l = 0;
            while (i < total)
            {
                s += words[i];
                // 倒数第二个
                if (i <= total - 2)
                {
                    s.resize(s.size() + space, ' ');
                    // 前k个余数多一个空格
                    if (l < k)
                    {
                        s += ' ';
                    }
                }

                ++l;
                ++i;
            }
            s.resize(maxWidth, ' ');
            res.push_back(s);
        }
        // 最后一行左对齐
        string s;
        while (i < total + rowNums[rowNums.size() - 1])
        {
            s += words[i] + ' ';
            ++i;
        }
        s.resize(maxWidth, ' ');
        res.push_back(s);
        
        return res;
    }
};

int main()
{
    // vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    vector<string> res = Solution().fullJustify(words, 16);
}