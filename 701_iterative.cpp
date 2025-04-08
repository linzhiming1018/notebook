#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *cur = root;
        while (true) {
            if (val < cur->val) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }
        return root;
    }
};
