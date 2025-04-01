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
        assert(inEnd - inBegin == postEnd - postBegin);
        auto *root = new TreeNode(postorder[postEnd]);

        // Find rootIndex
        int rootIndex = inBegin;
        while (inorder[rootIndex] != postorder[postEnd]) {
            ++rootIndex;
        }

        root->left = helper(inorder, postorder, inBegin, rootIndex - 1, postBegin, rootIndex - 1);
        root->right = helper(inorder, postorder, rootIndex + 1, inEnd, rootIndex, postEnd - 1);
        return root;
    }
};
