#include "TreeNode.hpp"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            if (root->left != nullptr)
                s.push(root->left);
            if (root->right != nullptr)
                s.push(root->right);
        }
        reverse(ans.begin(), ans.end()); // 根右左 -> 左右根
        return ans;
    }
};
