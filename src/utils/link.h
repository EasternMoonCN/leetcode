//
// Created by EasternMoon on 2024/6/27.
//

#ifndef LEETCODE_LINK_H
#define LEETCODE_LINK_H

#include "common.cpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class link {

};


#endif //LEETCODE_LINK_H
