#include "TreeNode.hpp"

class Solution {
public:
    int minDiffInBST(TreeNode *root) {
        TreeNode *pre = nullptr;
        int minDiff = INT_MAX;
        preorder(root, pre, minDiff);
        return minDiff;
    }

private:
    void preorder(TreeNode *root, TreeNode *&pre, int &minDiff) {
        if (!root) return;
        preorder(root->left, pre, minDiff);
        if (pre && root->val - pre->val < minDiff) minDiff = root->val - pre->val;
        pre = root;
        preorder(root->right, pre, minDiff);
    }
};
