#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) root = root->left;
            else if (p->val > root->val && q->val > root->val) root = root->right;
            else return root;
        }
        return nullptr; // Should never reach here if p and q exist in tree
    }
};
