#include "TreeNode.hpp"

class Solution {
public:
    bool isSameTree(TreeNode *x, TreeNode *y) {
        if (!x || !y) return x == y;
        return x->val == y->val && isSameTree(x->left, y->left) && isSameTree(x->right, y->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root) return !subRoot;
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
