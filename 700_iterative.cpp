#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root) {
            if (val == root->val) return root;
            if (val < root->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};
