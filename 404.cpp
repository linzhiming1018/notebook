#include "TreeNode.hpp"

class Solution {
public:
    // Post-order
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
};
