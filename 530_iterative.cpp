#include "TreeNode.hpp"

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        if (!root || (!root->left && !root->right)) return 0;
        stack<TreeNode *> s;
        const TreeNode *pre = nullptr;
        int minDiff = INT_MAX;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (pre && root->val - pre->val < minDiff) minDiff = root->val - pre->val;
            pre = root;
            root = root->right;
        }
        return minDiff;
    }
};
