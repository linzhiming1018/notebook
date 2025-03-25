#include "Node_429.hpp"

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            vector<int> curLevel;
            for (int i = 0; i < curSize; i++)
            {
                Node *curNode = q.front();
                curLevel.push_back(curNode->val);
                q.pop();
                for (auto child : curNode->children)
                {
                    if (child)
                        q.push(child);
                }
            }
            ans.push_back(curLevel);
        }
        return ans;
    }
};
