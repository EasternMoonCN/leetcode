#include "utils/common.cpp"

int main() {
    vector<int> nums1 = {1, 3, 4, 2, 6};
    /**
     * priority_queue:优先级越高，排名越靠后，最低优先级排在堆头
     */
    auto comp = [](int a, int b) {
        return a > b;
    };
    // priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    // priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < nums1.size(); i++)
    {
        pq.push(nums1[i]);
    }
    
    while (!pq.empty())
    {
        cout << pq.top() << ",";
        pq.pop();
    }
    

    return 0;
}