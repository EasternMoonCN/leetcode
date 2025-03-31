/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> qnode;
        qnode.push(root);
        bool odd = true;
        while (!qnode.empty()) {
            int size = qnode.size();
            vector<TreeNode* > nodes;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode.front(); qnode.pop();
                if (odd && node->left) {
                    // swap(node->left->val, node->right->val);
                    nodes.push_back(node->left);
                    nodes.push_back(node->right);
                }
                if (node->left) {
                    qnode.push(node->left);
                    qnode.push(node->right);
                }
            }

            if (odd) {
                for (int i = 0, j = nodes.size() - 1; i < j; ++i, --j) {
                    swap(nodes[i]->val, nodes[j]->val);
                }
            }
            odd = !odd;
        }
        return root;
    }

    // TreeNode* reverseOddLevels(TreeNode* root) {
    //     auto dfs = [&](this auto && dfs, TreeNode* p, TreeNode* q, bool odd) -> void {
    //         if (!p) {
    //             return;
    //         }
    //         if (odd) {
    //             swap(p->val, q->val);
    //         }
    //         dfs(p->left, q->right, !odd);
    //         dfs(p->right, q->left, !odd);
    //     };
    //     dfs(root->left, root->right, true);
    //     return root;
    // }
};