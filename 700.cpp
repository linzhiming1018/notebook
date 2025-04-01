#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root || val == root->val)
            return root;
        if (val < root->val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};
