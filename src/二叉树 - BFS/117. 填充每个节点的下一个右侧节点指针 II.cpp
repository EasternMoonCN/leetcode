#include "../utils/common.h"
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> qnode;
        qnode.push(root);
        while(!qnode.empty()) {
            int size = qnode.size();
            for (int i = 0; i < size; ++i) {
                Node* node = qnode.front(); qnode.pop();
                if (i != size - 1) node->next = qnode.front();
                if (node->left) qnode.push(node->left);
                if (node->right) qnode.push(node->right);
            }
        }
        return root;
    }
};