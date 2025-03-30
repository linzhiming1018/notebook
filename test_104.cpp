#include <cassert>
#include "104.cpp"

// Helper function to delete the tree
void deleteTree(TreeNode *root) {
 if (root == nullptr)
  return;
 deleteTree(root->left);
 deleteTree(root->right);
 delete root;
}

void testMaxDepth() {
 Solution solution;

 // Test case 1: Empty tree
 assert(solution.maxDepth(nullptr) == 0);
 assert(solution.maxDepth_bfs(nullptr) == 0);

 // Test case 2: Single node
 TreeNode *root1 = new TreeNode(1);
 assert(solution.maxDepth(root1) == 1);
 assert(solution.maxDepth_bfs(root1) == 1);

 // Test case 3: Balanced tree
 /*
      1
     / \
    2   3
 */
 TreeNode *root2 = new TreeNode(1);
 root2->left = new TreeNode(2);
 root2->right = new TreeNode(3);
 assert(solution.maxDepth(root2) == 2);
 assert(solution.maxDepth_bfs(root2) == 2);

 // Test case 4: Unbalanced tree
 /*
      1
     /
    2
   /
  3
 */
 TreeNode *root3 = new TreeNode(1);
 root3->left = new TreeNode(2);
 root3->left->left = new TreeNode(3);
 assert(solution.maxDepth(root3) == 3);
 assert(solution.maxDepth_bfs(root3) == 3);

 // Test case 5: Complete binary tree
 /*
       1
      / \
     2   3
    / \
   4   5
 */
 TreeNode *root4 = new TreeNode(1);
 root4->left = new TreeNode(2);
 root4->right = new TreeNode(3);
 root4->left->left = new TreeNode(4);
 root4->left->right = new TreeNode(5);
 assert(solution.maxDepth(root4) == 3);
 assert(solution.maxDepth_bfs(root4) == 3);

 // Clean up memory
 delete root1;
 deleteTree(root2);
 deleteTree(root3);
 deleteTree(root4);

 cout << "All tests passed!" << endl;
}

int main() {
 testMaxDepth();
 return 0;
}
