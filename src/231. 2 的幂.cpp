class Solution {
    public:
        // bool isPowerOfTwo(int n) {
        //     // 2 的幂不为负数
        //     if (n <= 0) {
        //         return false;
        //     }
        //     return !(n & (n - 1));
        // }
        //  bool isPowerOfTwo(int n) {
        //     if (n <= 0) {
        //         return false;
        //     }
        //     function<bool(int)> dfs = [&](int num) -> bool {
        //         if (num == 1) {
        //             return true;
        //         }
        //         if (!(num & 1)) {
        //             return dfs(num >> 1);
        //         }
        //         return false;
        //     };
        //     return dfs(n);
        // }
    
        bool isPowerOfTwo(int n) {
            if (n <= 0) {
                return false;
            }
            while (true) {
                if (n == 1) {
                    return true;
                }
                if (n & 1) {
                    return false;
                }
                n >>= 1;
            }
        }
    };