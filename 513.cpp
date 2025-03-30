#include "TreeNode.hpp"

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int ans;
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *cur = q.front();
                if (i == 0) ans = cur->val;
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return ans;
    }

    int ans;
    int maxDepth = INT_MIN;

    void traverse(TreeNode *root, int depth) {
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                ans = root->val;
            }
            return;
        }
        if (root->left) {
            ++depth;
            traverse(root->left, depth);
            --depth;
        }
        if (root->right) {
            ++depth;
            traverse(root->right, depth);
            --depth;
        }
    }

    int findBottomLeftValueRecursive(TreeNode *root) {
        traverse(root, 0);
        return ans;
    }
};
