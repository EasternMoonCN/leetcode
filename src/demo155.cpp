//
// Created by EasternMoon on 2024/7/2.
//
#include "utils/head.h"

class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        data_stack.push(val);
        // 栈顶为插入val为止的最小值
        min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
        data_stack.pop();
        min_stack.pop();
    }

    int top() {
        return data_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};


//class MinStack {
//private:
//    vector<int> data;
//    int size;
//    int minVal;
//public:
//    MinStack() {
//        size = 0;
//        minVal = INT_MAX;
//    }
//
//    void push(int val) {
//        data.push_back(val);
//        size++;
//        minVal = min(minVal, val);
//    }
//
//    void pop() {
//        data.pop_back();
//        size--;
//        auto it = min_element(data.begin(), data.end());
//        if (it == data.end()) {
//            minVal = INT_MAX;
//        } else {
//            minVal = *it;
//        }
//
//    }
//
//    int top() {
//        return data[size - 1];
//    }
//
//    int getMin() {
//        return minVal;
//    }
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minstack = MinStack();
    minstack.push(2147483646);
    minstack.push(2147483646);
    minstack.push(2147483647);
    cout << minstack.top() << endl;
    minstack.pop();
    cout << minstack.getMin() << endl;
    minstack.pop();
    cout << minstack.getMin() << endl;
    minstack.pop();
    minstack.push(2147483647);
    cout << minstack.top() << endl;
    cout << minstack.getMin() << endl;
}