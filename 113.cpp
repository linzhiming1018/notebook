#include "TreeNode.hpp"

class Solution {
public:
    void traverse(TreeNode *root, int remaining, vector<int> &path, vector<vector<int> > &ans) {
        // Base case: reached a leaf node
        if (!root->left && !root->right) {
            if (remaining == 0) ans.push_back(path);
            return;
        }
        // Traverse left subtree
        if (root->left) {
            remaining -= root->left->val;
            path.push_back(root->left->val);
            traverse(root->left, remaining, path, ans);
            // Backtrack
            remaining += root->left->val;
            path.pop_back();
        }
        // Traverse right subtree
        if (root->right) {
            remaining -= root->right->val;
            path.push_back(root->right->val);
            traverse(root->right, remaining, path, ans);
            // Backtrack
            remaining += root->right->val;
            path.pop_back();
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int targetSum) {
        vector<vector<int> > ans;
        if (!root) return ans;
        vector<int> path;
        path.push_back(root->val);
        traverse(root, targetSum - root->val, path, ans);
        return ans;
    }
};
