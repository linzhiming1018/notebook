#include "TreeNode.hpp"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int maxDepth_bfs(TreeNode *root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++depth;
        }
        return depth;
    }
};
