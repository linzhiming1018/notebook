#include "TreeNode.hpp"

class Solution {
public:
    bool check(const TreeNode *left, const TreeNode *right) {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        else if (left->val != right->val)
            return false;
        bool inside = check(left->right, right->left);
        bool outside = check(left->left, right->right);
        return inside && outside;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return check(root->left, root->right);
    }

    bool isSymmetric_level(TreeNode *root) {
        if (root == nullptr) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr && right != nullptr || left != nullptr && right == nullptr || left->val != right->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
