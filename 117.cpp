#include "Node_116.hpp"

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            Node *preNode = nullptr;
            for (int i = 0; i < curSize; i++)
            {
                Node *curNode = q.front();
                if (preNode)
                    preNode->next = curNode;
                q.pop();
                if (curNode->left)
                    q.push(curNode->left);
                if (curNode->right)
                    q.push(curNode->right);
                preNode = curNode;
            }
        }
        return root;
    }
};