#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return helper(nums, 0, nums.size());
    }

private:
    TreeNode *helper(vector<int> &nums, int begin, int end) {
        if (begin >= end) return nullptr;
        int maxIndex = begin;
        for (int i = begin + 1; i < end; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        auto *root = new TreeNode(nums[maxIndex]);
        root->left = helper(nums, begin, maxIndex);
        root->right = helper(nums, maxIndex + 1, end);
        return root;
    }
};
