class Solution {
public:
    const int MX = 100001;
    const int MOD = 1000000007;
    vector<long long> f, g;

    Solution() {
        f = vector<long long>(MX, 0);
        g = vector<long long>(MX, 0);
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;
        for (int i = 4; i < MX; ++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }
    }

    int countTexts(string pressedKeys) {
        int cnt = 0;
        long long res = 1;
        for (int i = 0; i < pressedKeys.size(); ++i) {
            cnt++;
            if (i == pressedKeys.size() - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
                if (pressedKeys[i] != '7' && pressedKeys[i] != '9') {
                    res = res * f[cnt] % MOD;
                } else {
                    res = res * g[cnt] % MOD;
                }
                cnt = 0;
            }
        }
        return res;
    }
};