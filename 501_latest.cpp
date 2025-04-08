#include "TreeNode.hpp"

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode *root, vector<int> &ans) {
        stack<TreeNode *> s;
        const TreeNode *pre = nullptr;
        int maxFreq = 0;
        int freq = 0;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (!pre || root->val != pre->val) freq = 1;
            else freq++;
            if (freq > maxFreq) {
                maxFreq = freq;
                ans.clear(); // Invalidate previous results
                ans.push_back(root->val);
            } else if (freq == maxFreq) {
                ans.push_back(root->val);
            }
            pre = root;
            root = root->right;
        }
    }
};
