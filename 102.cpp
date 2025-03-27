#include "TreeNode.hpp"

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> curLevel;
            int curSize = q.size(); // `q.size()` may change inside for-loop.
            for (int i = 0; i < curSize; i++) {
                TreeNode *curNode = q.front();
                curLevel.push_back(curNode->val);
                q.pop();
                if (curNode->left != nullptr)
                    q.push(curNode->left);
                if (curNode->right != nullptr)
                    q.push(curNode->right);
            }
            ans.push_back(curLevel);
        }
        return ans;
    }
};
