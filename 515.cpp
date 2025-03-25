#include "TreeNode.hpp"

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            int curMax = 0x80000000;
            for (int i = 0; i < curSize; i++)
            {
                TreeNode *curNode = q.front();
                if (curNode->val > curMax)
                    curMax = curNode->val;
                q.pop();
                if (curNode->left)
                    q.push(curNode->left);
                if (curNode->right)
                    q.push(curNode->right);
            }
            ans.push_back(curMax);
        }
        return ans;
    }
};