#include "TreeNode.hpp"

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> um;
        inorder(root, um);
        vector<pair<int, int> > v(um.begin(), um.end());
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        if (v.empty()) return ans;
        for (const auto &p: v) {
            if (p.second == v[0].second) ans.push_back(p.first);
            else break;
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

    bool static cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};
