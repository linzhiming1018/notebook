#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode *invertTree_bfs(TreeNode *root) {
        if (!root) return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize(); i++) {
                TreeNode *curNode = q.front();
                swap(curNode->left, curNode->right);
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
        }
        return root;
    }
};
