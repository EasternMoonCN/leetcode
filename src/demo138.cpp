//
// Created by EasternMoon on 2024/6/29.
//


#include "utils/head.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 源节点对于的拷贝节点
    unordered_map<Node*, Node*> createdNode;
    Node* copyRandomList(Node* head) {
        // 头节点为空直接返回
        if (!head) {
            return nullptr;
        }
        // head 节点对于拷贝是否已经创建
        if (!createdNode.count(head)) {
            // 创建拷贝节点
            Node* copyNode = new Node(head->val);
            // 存储映射关系
            createdNode[head] = copyNode;
            // 递归创建拷贝的下一个节点
            copyNode->next = copyRandomList(head->next);
            // 递归创建拷贝的随机节点
            copyNode->random = copyRandomList(head->random);
        }
        // 返回head节点对于拷贝节点
        return createdNode[head];
    }
};

int main() {
    Node node1(7);
    Node node2(13);
    Node node3(11);
    Node node4(10);
    Node node5(1);
    node1.next = &node2;
    node2.next = &node3;
    node2.random = &node1;
    node3.next = &node4;
    node3.random = &node5;
    node4.next = &node5;
    node4.random = &node3;
    node5.random = &node1;

    Node* head = Solution().copyRandomList(&node1);
    Node * cur = head;
    while (cur) {
        cout << cur->val  << " ";
        Node * temp = cur;
        cur = cur->next;
        delete temp;
    }
}
