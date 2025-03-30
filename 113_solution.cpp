#include "TreeNode.hpp"

class Solution {
public:
    void traverse(TreeNode *root, int remaining, vector<int> &path, vector<vector<int> > &ans) {
        // Base case: reached a leaf node
        if (!root->left && !root->right) {
            if (remaining == 0) ans.push_back(path);
            return;
        }

        // Process left subtree
        if (root->left) {
            path.push_back(root->left->val);
            traverse(root->left, remaining - root->left->val, path, ans);
            path.pop_back();
        }

        // Process right subtree
        if (root->right) {
            path.push_back(root->right->val);
            traverse(root->right, remaining - root->right->val, path, ans);
            path.pop_back();
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int targetSum) {
        vector<vector<int> > ans;
        if (!root) return ans;
        vector<int> path = {root->val};
        traverse(root, targetSum - root->val, path, ans);
        return ans;
    }
};
