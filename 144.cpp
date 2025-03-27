#include "TreeNode.hpp"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> s;
        while (root != nullptr || !s.empty()) {
            if (root != nullptr) {
                ans.push_back(root->val);
                s.push(root);
                root = root->left;
            } else {
                root = s.top()->right;
                s.pop();
            }
        }
        return ans;
    }
};
