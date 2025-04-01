#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return nullptr;
        if (!root1 || !root2) return root1 ? root1 : root2;
        queue<TreeNode *> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty()) {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();
            node1->val += node2->val;
            if (node1->left && node2->left) {
                q.push(node1->left);
                q.push(node2->left);
            }
            if (node1->right && node2->right) {
                q.push(node1->right);
                q.push(node2->right);
            }
            if (!node1->left && node2->left) {
                node1->left = node2->left;
            }
            if (!node1->right && node2->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
