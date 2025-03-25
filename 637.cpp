#include "TreeNode.hpp"

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            double curSum = 0;
            for (int i = 0; i < curSize; i++)
            {
                TreeNode *curNode = q.front();
                curSum += curNode->val;
                q.pop();
                if (curNode->left)
                    q.push(curNode->left);
                if (curNode->right)
                    q.push(curNode->right);
            }
            ans.push_back(curSum / curSize);
        }
        return ans;
    }
};