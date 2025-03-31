#include "utils/common.cpp"

class MedianFinder {
private:
    // 大顶堆，存储小于中位数的元素 或 中位数
    priority_queue<int, vector<int>, less<int>> pqMin;
    // 小顶堆，存储小于中位数的元素
    priority_queue<int, vector<int>, greater<int>> pqMax;
    int minSize, maxSize;

public:

    MedianFinder() {
        minSize = maxSize = 0;
    }
    
    void addNum(int num) {
        if (minSize == 0) {
            pqMin.push(num);
            minSize++;
        } else {
            if (minSize <= maxSize) {
                if (num > pqMax.top()) {
                    pqMin.push(pqMax.top());
                    pqMax.pop();
                    pqMax.push(num);
                } else {
                    pqMin.push(num);
                }
                minSize++;
            } else {
                if(num >= pqMin.top()) {
                    pqMax.push(num);
                } else {
                    pqMax.push(pqMin.top());
                    pqMin.pop();
                    pqMin.push(num);
                }
                maxSize++;
            }
        }
    }
    
    double findMedian() {
        if (minSize == maxSize) {
            return (pqMin.top() + pqMax.top()) / 2.;
        } else {
            return pqMin.top();
        }
    }
};

class MedianFinder2 {
private:
    multiset<int> sets;
    multiset<int>::iterator left, right;
public:

    MedianFinder2() {
    }
    
    void addNum(int num) {
        sets.insert(num);
        if (sets.size() == 1)
        {
            left  = right = sets.begin();
        } else {
            if (left == right) {
                if(num >= *right) {
                    right++;
                } else {
                    left--;
                }
            } else {
                if (num >= *right) {
                    left++;
                } else if (num < *left) {
                    right--;
                } else {
                    left++;
                    right--;
                }
            }
        }
        
    }
    
    double findMedian() {
        if (left == right) {
            return *left;
        } else {
            return (*left + *right)/2.;
        }
    }
};

int main() {

    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    cout << param_2;
    return 0;
 
}