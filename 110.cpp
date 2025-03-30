#include "TreeNode.hpp"

class Solution {
public:
    // Post-order traversal
    // Returns as soon as an unbalanced subtree is found
    int getHeight(TreeNode *root) {
        if (!root) return 0;

        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced

        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced

        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root) {
        return getHeight(root) != -1;
    }
};
