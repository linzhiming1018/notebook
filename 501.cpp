#include "TreeNode.hpp"

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> um;
        inorder(root, um);
        vector<int> ans;
        int maxFreq = 0;
        for (const auto &p: um) {
            if (p.second > maxFreq) {
                maxFreq = max(maxFreq, p.second);
            }
        }
        for (const auto &p: um) {
            if (p.second == maxFreq) ans.push_back(p.first);
        }
        return ans;
    }

private:
    void inorder(TreeNode *root, unordered_map<int, int> &um) {
        if (!root) return;
        inorder(root->left, um);
        um[root->val]++;
        inorder(root->right, um);
    }
};
