#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 使用 std::greater 实现最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(15);

    std::cout << "Top element (smallest): " << minHeap.top() << std::endl; // 输出 5

    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}
