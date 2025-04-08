#include "TreeNode.hpp"

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        vector<int> ans;
        inorder(root, ans);
        if (ans.size() < 2) return 0;
        int minDiff = ans[1] - ans[0];
        for (int i = 2; i < ans.size(); i++) {
            if (ans[i] - ans[i - 1] < minDiff) minDiff = ans[i] - ans[i - 1];
        }
        return minDiff;
    }

private:
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};
