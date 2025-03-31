#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, const int inBegin, const int inEnd,
                     const int postBegin, const int postEnd) {
        if (inBegin > inEnd || postBegin > postEnd) return nullptr;
        auto *root = new TreeNode(postorder[postEnd]);

        // Find rootIndex
        int rootIndex = inBegin;
        while (inorder[rootIndex] != postorder[postEnd]) {
            ++rootIndex;
        }

        int leftSize = rootIndex - inBegin;
        root->left = helper(inorder, postorder, inBegin, rootIndex - 1, postBegin, postBegin + leftSize - 1);
        root->right = helper(inorder, postorder, rootIndex + 1, inEnd, postBegin + leftSize, postEnd - 1);
        return root;
    }
};
