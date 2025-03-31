#include "utils/common.cpp"

/**
 * 
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。


示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        backTrack(s, 0, 0, "", results);
        return results;
    }

    void backTrack(string s, int begin, int splitNum, string result, vector<string>& results) {
        // 剩下的字符串长度太长了，划分最大长度完了之后还有剩余
        if (3 * (4 - splitNum) < s.size() - begin) {
            return;
        }

        // 划分了四次了
        if (splitNum == 4) {
            // 原字符串都用到了（加上了三个.）
            if (s.size() + 3 == result.size()) {
                results.push_back(result);
            }
            return;
        }

        // 每次选择的ip地址每个长度最多为3
        for (int len = 1; len <= 3 && begin + len <= s.size(); ++len) {
            string temp = s.substr(begin, len);
            if(isValid(temp)) {
                if (result != "") {
                    temp = result + "." + temp;
                }

                //begin + len:下一次开始位置，为本次结束位置（ip地址之间是连续的）
                backTrack(s, begin + len, splitNum + 1, temp, results);
            } else {
                continue;
            }
        }
    }

    bool isValid(string temp) {
        if (temp.size() > 1 && temp[0] == '0') {
            return false;
        }
        int val = stoi(temp);
        return val >= 0 && val <= 255;
    }


    vector<string> restoreIpAddresses2(string s) {
        vector<string> results;
        backTrack2(s, {}, results, 1);
        return results;
    }

    /**
     * nums 存储划分结束位置
     */
    void backTrack2(string s, vector<int> nums, vector<string>& results, int start) {
        // 有三个划分了
        if (nums.size() == 3) {
            // 最后一个结束位置在末尾（保证划分整个长度）
            nums.push_back(s.size());
            // 解析后在ip地址
            string ipAddress = splitIpAddress(s, nums);
            if (ipAddress != "") {
                results.push_back(ipAddress);
            }
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            nums.push_back(i);
            backTrack2(s, nums, results, i + 1);
            nums.pop_back();
        }
    }

    string splitIpAddress(string s, vector<int> nums) {
        int start = 0;
        string result = "";
        for (int end : nums) {
            // 根据起始和结束位置求子串
            string temp = s.substr(start, end - start);
            // 子串是否是有效的ip地址
            if (isValid2(temp)) {
                // 非第一个元素首先加.
                if (start != 0) {
                    result += ".";
                }
                result = result + temp;
                // 更新起点
                start = end;
            } else {
                return "";
            }
        }
        return result;
    }

    bool isValid2(string s) {
        // 不允许前导0
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        // 字符串过长（超过255）
        if (s.size() > 3) {
            return false;
        }
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            num = num * 10 + (s[i] - '0');
        }
        // 是否位于0-255
        return num >= 0 && num <= 255;
    }

};

int main() {
    // vector<string> results = Solution().restoreIpAddresses("25525511135");
    // common<string>::printVector(results);
    cout << stoi("0123");
}