#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preBegin > preEnd || inBegin > inEnd) return nullptr;
        assert(preEnd - preBegin == inEnd - inBegin);
        TreeNode *root = new TreeNode(preorder[preBegin]);
        int rootIndex = inBegin;
        while (inorder[rootIndex] != root->val) {
            rootIndex++;
        }
        int leftSize = rootIndex - inBegin;
        root->left = helper(preorder, inorder, preBegin + 1, preBegin + leftSize, inBegin, rootIndex - 1);
        root->right = helper(preorder, inorder, preBegin + leftSize + 1, preEnd, rootIndex + 1, inEnd);
        return root;
    }
};
