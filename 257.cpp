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

    void traversal_new(TreeNode *root, string path, vector<string> &ans) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            path += "->";
            traversal_new(root->left, path, ans);
            path.pop_back();
            path.pop_back();
        }
        if (root->right) {
            path += "->";
            traversal_new(root->right, path, ans);
            path.pop_back();
            path.pop_back();
        }
    }

    void traversal_latest(TreeNode *root, string path, vector<string> &ans) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            traversal_latest(root->left, path + "->", ans);
        }
        if (root->right) {
            traversal_latest(root->right, path + "->", ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        if (!root) return ans;
        string path;
        traversal_latest(root, path, ans);
        return ans;
    }
};
