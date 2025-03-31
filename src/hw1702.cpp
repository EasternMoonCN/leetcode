#include "utils/common.cpp"
/**
 * 给你一个二进制字符串 binary ，它仅有 0 或者 1 组成。你可以使用下面的操作任意次对它进行修改：

操作 1 ：如果二进制串包含子字符串 "00" ，你可以用 "10" 将其替换。
比方说， "00010" -> "10010"
操作 2 ：如果二进制串包含子字符串 "10" ，你可以用 "01" 将其替换。
比方说， "00010" -> "00001"
请你返回执行上述操作任意次以后能得到的 最大二进制字符串 。如果二进制字符串 x 对应的十进制数字大于二进制字符串 y 对应的十进制数字，那么我们称二进制字符串 x 大于二进制字符串 y 。
 
 示例 1：

输入：binary = "000110"
输出："111011"
解释：一个可行的转换为：
"000110" -> "000101" 
"000101" -> "100101" 
"100101" -> "110101" 
"110101" -> "110011" 
"110011" -> "111011"
示例 2：

输入：binary = "01"
输出："01"
解释："01" 没办法进行任何转换。
 */
class Solution {
public:
    /**
     * 1. 字符串最终只有一个0
     * 2。 [011~10] => [101~11]
     */
       string maximumBinaryString(string binary) {
        int n = binary.size();
        // 还记录了上一次j的位置
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (binary[i] == '0') {
                j = max(i + 1, j);
                // 找到下一个为0的位置
                while (j < n && binary[j] == '1') {
                    j++;
                }
                // i，j位置都为0，且他们之间没有第二个0
                if (j < n) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }

    string maximumBinaryString2(string binary) {
        int n = binary.size();

        // 判断前面有没有0
        vector<bool> flag(n, true);
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '0') {
                break;
            } else {
                flag[i] = false;
            }
        }

        for (int i = n - 2; i > 0; --i) {
            if (!flag[i - 1]) {
                break;
            }
            if(binary.substr(i, 2) == "10") {
                binary.replace(i, 2, "01");
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (binary.substr(i, 2) == "00") {
                binary.replace(i, 2, "10");
            }
        }
        return binary;
    }
};