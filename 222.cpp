#include "TreeNode.hpp"

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countNodes_bfs(TreeNode *root) {
        if (!root) return 0;
        int count = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                ++count;
                TreeNode *curNode = q.front();
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
        }
        return count;
    }

    int countNodes_best(TreeNode *root) {
        if (!root)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftHeight = 0;
        int rightHeight = 0;
        while (left) {
            left = left->left;
            leftHeight++;
        }
        while (right) {
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight)
            return (2 << leftHeight) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
