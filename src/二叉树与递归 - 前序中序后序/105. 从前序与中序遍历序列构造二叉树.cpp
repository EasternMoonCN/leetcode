#include "../utils/tree.cpp"

class Solution {
public:
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder, int i, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        cout << i << endl;
        TreeNode* root = new TreeNode(preorder[i]);
        auto it = find(inorder.begin() + left, inorder.begin() + right + 1, preorder[i]);
        // 左子树数: it - inorder.begin() - left
        // 右子树树: inorder.end() - right - it - 1
        // 左子树根节点：i+1, left, it - inorder.begin() - 1
        // 右子树根节点：i + it - inorder.begin() - left + 1, it - inorder.begin() + 1, right
        root->left = buildTree(preorder, inorder, i + 1, left, it - inorder.begin() - 1);
        root->right = buildTree(preorder, inorder, i + (it - inorder.begin() - left) + 1, it - inorder.begin() + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        return buildTree(preorder, inorder, 0, 0, preorder.size() - 1);
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    cout << root->val;
}