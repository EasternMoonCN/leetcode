#include "utils/common.cpp"

class Solution
{
public:
    bool isNumber2(string s)
    {
        /**
         * R"" :原始字符，后面不再转义
         * ? : 一个或0个，+：一个或多个，*：0个或多个
         * ([+-]?(\d+(\.\d*)?|\.\d+)
         *      [+-]? ：匹配一次或0次 + 或 -
         *      (\d+(\.\d*)?|\.\d+)： 匹配数字.数字 或 .数字
         *          \d+ : 匹配一个或多个数字
         *          (\.\d*)?: 匹配小数部分
         *              \d*: 匹配0个或多个数字
         *          \.\d+: 匹配 小数点 带 一个或多个数字
         * ([eE][+-]?\d+)?)：匹配一个或0个指数部分
         *
         */
        regex pattern(R"([+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?)");
        return regex_match(s, pattern);
    }

    bool isNumber3(string s)
    {
        int index = 0, n = s.size();
        // 找E或e
        while (index < n)
        {
            if (s[index] == 'e' || s[index] == 'E')
            {
                break;
            }
            index++;
        }
        if (index < n)
        {
            return isDec(s.substr(0, index)) && isInteger(s.substr(index + 1, n - index - 1));
        }
        else
        {
            return isDec(s);
        }
    }

    bool isInteger(string s)
    {
        if (s == "")
        {
            return false;
        }
        int n = s.size(), index = 0;
        while (index < n)
        {
            char c = s[index];
            if (c == '+' || c == '-')
            {
                // 加减号未出现在首位
                if (index != 0)
                {
                    return false;
                }

                if (index + 1 >= n)
                {
                    return false;
                }

                if (!isdigit(s[index + 1]) && s[index + 1] != '.')
                {
                    return false;
                }
            }
            else if (!isdigit(c))
            {
                return false;
            }
            ++index;
        }
        return true;
    }

    bool isDec(string s)
    {
        if (s == "")
        {
            return false;
        }
        int n = s.size(), index = 0;
        bool hasDot = false;
        while (index < n)
        {
            char c = s[index];
            if (c == '+' || c == '-')
            {
                // 加减号未出现在首位
                if (index != 0)
                {
                    return false;
                }

                if (index + 1 >= n)
                {
                    return false;
                }

                if (!isdigit(s[index + 1]) && s[index + 1] != '.')
                {
                    return false;
                }
            }
            else if (c == '.')
            {
                if (hasDot)
                {
                    return false;
                }
                // 前或后需要有一位数字
                if (index > 0 && isdigit(s[index - 1]) || index + 1 < n && isdigit(s[index + 1]))
                {
                    hasDot = true;
                }
                else
                {
                    return false;
                }
            }
            else if (!isdigit(c))
            {
                return false;
            }
            ++index;
        }
        return true;
    }

    /**
     *
     * 符号位
    整数部分
    左侧有整数的小数点
    左侧无整数的小数点（根据前面的第二条额外规则，需要对左侧有无整数的两种小数点做区分）
    小数部分
    字符 e
    指数部分的符号位
    指数部分的整数部分
    */
    enum State
    {
        STATE_INIT,
        STATE_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INTEGER,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INTEGER
    };

    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    };

    CharType toCharType(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return CHAR_NUMBER;
        }
        if (c == 'e' || c == 'E')
        {
            return CHAR_EXP;
        }
        if (c == '.')
        {
            return CHAR_POINT;
        }
        if (c == '+' || c == '-')
        {
            return CHAR_SIGN;
        }
        return CHAR_ILLEGAL;
    }

    // 当前所处状态 当前字符类型  转移到到状态
    unordered_map<State, unordered_map<CharType, State>> transfer = {
        {
            STATE_INIT,
            {
                {CHAR_SIGN, STATE_SIGN},
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INTEGER}
            }
        },

        {
            STATE_SIGN,
            {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INTEGER}
            }
        },

        {
            STATE_INTEGER,
            {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT},
                {CHAR_EXP, STATE_EXP}
            }
        },

        {
            STATE_POINT_WITHOUT_INTEGER,
            {
                {CHAR_NUMBER, STATE_FRACTION}
            }
        },

        {
            STATE_POINT,
            {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP}
            }
        },

        {
            STATE_FRACTION,
            {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP}
            }
        },

        {
            STATE_EXP,
            {
                {CHAR_SIGN, STATE_EXP_SIGN},
                {CHAR_NUMBER, STATE_EXP_INTEGER}
            }
        },

        {
            STATE_EXP_SIGN,
            {
                {CHAR_NUMBER, STATE_EXP_INTEGER}
            }
        },

        {
            STATE_EXP_INTEGER,
            {
                {CHAR_NUMBER, STATE_EXP_INTEGER}
            }
        }
    };

    bool isNumber(string s)
    {
        int n = s.size();
        // 初始状态
        State state = STATE_INIT;
        for (int i = 0; i < n; ++i)
        {
            CharType charType = toCharType(s[i]);
            if (transfer[state].find(charType) == transfer[state].end())
            {
                return false;
            }
            else
            {
                state = transfer[state][charType];
            }
        }
        return state == STATE_INTEGER || state == STATE_POINT || state == STATE_FRACTION || state == STATE_EXP_INTEGER;
    }
};

int main()
{
    char c = 'a';
    cout << isdigit(c) << endl;
    cout << tolower(c) << endl;
}