#include "TreeNode.hpp"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // `!p || !q` is true when there's at least 1 nullptr
        if (!p || !q) return p == q;
        // Both p and q are not nullptr
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    bool isSameTree_iterative(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        que.push(p);
        que.push(q);

        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();

            // Both null - continue checking other nodes
            if (!node1 && !node2) continue;

            // One null or different values - trees are different
            if (!node1 || !node2 || node1->val != node2->val) return false;

            // Add children in corresponding pairs
            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);
        }
        return true;
    }
};
