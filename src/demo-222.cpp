#include "./utils/tree.h"
#include <cmath>

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {     // 判断mid节点是否存在
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    /**
     * 在完全二叉树中，判断节点k是否存在
     * k（12）
     * 1100 最高位（最高为1）到最低位包含4位（2^（3+1）），位于第3层
     *  100 从高位到低位表示了从根节点到节点k的路径
     */
    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);    // 最高位为1，其余位为0，用来判断k的二进制去除最高位的其余各位
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {          // 从高位开始，判断bits中最高位的值（1右节点，0左节点）
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;         // 到达最终节点后，判断节点是否存在
    }


    // int countNodes(TreeNode* root) {
    //     if (!root) {
    //         return 0;
    //     }
    //     if(!root->left && !root->right) {
    //         return 1;
    //     }
    //     // 左子树数量 + 右子树数量 + 当前节点
    //     return countNodes(root->left) + countNodes(root->right) + 1;
    // }
};

/**
 *       1
 *    2     3
 *   4  5  6
*/
int main() {
    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    TreeNode n4 = TreeNode(4);
    TreeNode n5 = TreeNode(5);
    TreeNode n6 = TreeNode(6);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    cout << Solution().countNodes(&n1) << endl;
}