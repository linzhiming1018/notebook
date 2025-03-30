#include "TreeNode.hpp"

class Solution {
public:
    // Pre-order traversal
    bool traverse(TreeNode *root, int remaining) {
        remaining -= root->val;
        if (!root->left && !root->right) {
            return remaining == 0;
        }
        if (root->left && traverse(root->left, remaining)) {
            return true;
        }
        if (root->right && traverse(root->right, remaining)) {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        return traverse(root, targetSum);
    }
};
