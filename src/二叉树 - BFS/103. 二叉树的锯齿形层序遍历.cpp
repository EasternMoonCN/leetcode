#include "../utils/tree.h"
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> qnode;
        qnode.push(root);
        bool event = false;
        
        while (!qnode.empty()) {
            int size = qnode.size();
            vector<int> num(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode.front(); qnode.pop();
                num[i] = node->val;
                if (node->left) {
                    qnode.push(node->left);
                }
                if (node->right) {
                    qnode.push(node->right);
                }
            }
            if (event) {
                reverse(num.begin(), num.end());
            }
            res.push_back(num);
            event = !event;
        }
        return res;
    }

    vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> qnode;
        qnode.push(root);
        bool event = false;
        while (!qnode.empty()) {
            int size = qnode.size();
            deque<int> num;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode.front(); qnode.pop();
                if (event) num.push_front(node->val);
                else num.push_back(node->val);

                if (node->left) qnode.push(node->left);
                if (node->right) qnode.push(node->right);
            }
            res.push_back(vector<int>(num.begin(), num.end()));
            event = !event;
        }
        return res;
    }
};