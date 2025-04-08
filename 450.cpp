#include "TreeNode.hpp"

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;
        // Find the node to delete
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            // Case 1: Leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            if (!root->left) {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
            if (!root->right) {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            // Case 3: Two children
            // Find successor (smallest in right subtree)
            TreeNode *tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            root->val = tmp->val; // Copy successor's value
            root->right = deleteNode(root->right, tmp->val); // Delete successor
        }
        return root;
    }
};
