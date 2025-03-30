#include "TreeNode.hpp"

class Solution {
public:
    int minDepth(TreeNode *root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *curNode = q.front();
                if (curNode->left == nullptr && curNode->right == nullptr) return depth + 1;
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            ++depth;
        }
        return depth;
    }
};
