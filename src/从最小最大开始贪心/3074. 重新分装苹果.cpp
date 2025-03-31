class Solution {
    public:
        // 按照容量从大到小选择箱子装苹果，直到所有苹果均装入箱子为止。
        int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
            sort(capacity.begin(), capacity.end(), greater<int>());
            int total = accumulate(apple.begin(), apple.end(), 0);
            int i = 0;
            while (total > 0) {
                total -= capacity[i++];
            }
            return i;
        }
    };