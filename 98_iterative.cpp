#include "TreeNode.hpp"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        const TreeNode *pre = nullptr;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            // Make sure `pre` exists before comparison
            if (pre && root->val <= pre->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

int main() {
    Solution solution;
    auto *root = new TreeNode(0);
    assert(solution.isValidBST(root));
    return 0;
}
