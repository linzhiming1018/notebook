#include "TreeNode.hpp"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> s;
        while (root != nullptr || !s.empty()) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *tmp = s.top();
                ans.push_back(tmp->val);
                s.pop();
                root = tmp->right;
            }
        }
        return ans;
    }
};
