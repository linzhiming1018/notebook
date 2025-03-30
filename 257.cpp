#include "TreeNode.hpp"

class Solution {
public:
    void traversal(TreeNode *root, vector<int> &path, vector<string> &ans) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            string strPath;
            for (int i = 0; i < path.size() - 1; i++) {
                strPath += to_string(path[i]) + "->";
            }
            strPath += to_string(path[path.size() - 1]);
            ans.push_back(strPath);
            return;
        }
        if (root->left) {
            traversal(root->left, path, ans);
            path.pop_back();
        }
        if (root->right) {
            traversal(root->right, path, ans);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        if (!root) return ans;
        vector<int> path;
        traversal(root, path, ans);
        return ans;
    }
};
