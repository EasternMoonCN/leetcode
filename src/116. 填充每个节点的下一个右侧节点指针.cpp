#include "utils/common.cpp"
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    // O(N)
    Node *connect(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        queue<Node *> qn;
        qn.push(root);
        Node *prev;
        while (!qn.empty())
        {
            int size = qn.size();
            prev = nullptr;
            for (int i = 0; i < size; ++i)
            {
                Node *curr = qn.front();
                qn.pop();

                if (prev)
                {
                    prev->next = curr;
                }
                prev = curr;

                if (curr->left)
                {
                    qn.push(curr->left);
                }
                if (curr->right)
                {
                    qn.push(curr->right);
                }
            }
        }
        return root;
    }

    Node *connect2(Node *root)
    {
        if (!root)
        {
            return root;
        }
        Node *leftMost = root;
        // 建立n+1层next指针
        while (leftMost->left)
        {
            Node *head = leftMost;
            // 遍历n层next指针
            while (head)
            {
                // 建立左右子节点next关系
                head->left->next = head->right;

                // 建立右子节点和下一个节点的做节点next关系
                if (head->next)
                {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }
};