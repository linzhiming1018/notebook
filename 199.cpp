#include "TreeNode.hpp"

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> curLevel;
            int curSize = q.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *curNode = q.front();
                curLevel.push_back(curNode->val);
                q.pop();
                if (curNode->left)
                    q.push(curNode->left);
                if (curNode->right)
                    q.push(curNode->right);
            }
            ans.push_back(curLevel.back());
        }
        return ans;
    }
};
