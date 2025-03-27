#include "TreeNode.hpp"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        if (root == NULL)
            return ans;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top(); // 中
            s.pop();
            ans.push_back(node->val);
            if (node->right)
                s.push(node->right); // 右（空节点不入栈）
            if (node->left)
                s.push(node->left); // 左（空节点不入栈）
        }
        return ans;
    }
};
