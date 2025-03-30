#include "113_solution.cpp"

// Helper function to create a tree from a level-order traversal array
// Using -1000 to represent null nodes
TreeNode *createTree(const std::vector<int> &values, int nullValue = -1000) {
    if (values.empty() || values[0] == nullValue) return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    for (size_t i = 1; i < values.size(); i += 2) {
        TreeNode *current = q.front();
        q.pop();

        // Create left child
        if (i < values.size() && values[i] != nullValue) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }

        // Create right child
        if (i + 1 < values.size() && values[i + 1] != nullValue) {
            current->right = new TreeNode(values[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}

// Helper function to delete the tree
void deleteTree(TreeNode *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to check if two sets of paths are equivalent
bool arePathsEqual(std::vector<std::vector<int> > &paths1, std::vector<std::vector<int> > &paths2) {
    if (paths1.size() != paths2.size()) return false;

    // Sort each path
    for (auto &path: paths1) {
        std::sort(path.begin(), path.end());
    }
    for (auto &path: paths2) {
        std::sort(path.begin(), path.end());
    }

    // Sort the collection of paths
    std::sort(paths1.begin(), paths1.end());
    std::sort(paths2.begin(), paths2.end());

    return paths1 == paths2;
}

// Helper function to print paths for debugging
void printPaths(const std::vector<std::vector<int> > &paths) {
    std::cout << "Paths: [" << std::endl;
    for (const auto &path: paths) {
        std::cout << "  [";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

// Test runner
void testPathSum() {
    Solution solution;
    int testsPassed = 0;
    int totalTests = 0;

    // Test case 1: Empty tree
    {
        totalTests++;
        std::cout << "Test case 1: Empty tree" << std::endl;
        TreeNode *root = nullptr;
        int targetSum = 0;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {};

        if (result == expected) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: []" << std::endl;
            printPaths(result);
        }
    }

    // Test case 2: Single node tree with matching sum
    {
        totalTests++;
        std::cout << "Test case 2: Single node tree with matching sum" << std::endl;
        TreeNode *root = new TreeNode(5);
        int targetSum = 5;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {{5}};

        if (result == expected) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: [[5]]" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 3: Single node tree with non-matching sum
    {
        totalTests++;
        std::cout << "Test case 3: Single node tree with non-matching sum" << std::endl;
        TreeNode *root = new TreeNode(5);
        int targetSum = 10;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {};

        if (result == expected) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: []" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 4: Standard example from LeetCode
    {
        totalTests++;
        std::cout << "Test case 4: Standard example from LeetCode" << std::endl;
        /*
             5
            / \
           4   8
          /   / \
         11  13  4
        /  \    / \
       7    2  5   1
        */
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(11);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);

        int targetSum = 22;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {{5, 4, 11, 2}, {5, 8, 4, 5}};

        if (arePathsEqual(result, expected)) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: [[5, 4, 11, 2], [5, 8, 4, 5]]" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 5: Tree with negative values
    {
        totalTests++;
        std::cout << "Test case 5: Tree with negative values" << std::endl;
        /*
              1
             / \
           -2   3
           /   / \
         -1   4  -5
        */
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(-2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(-1);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(-5);

        int targetSum = -2;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {{1, -2, -1}};

        if (arePathsEqual(result, expected)) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: [[1, -2, -1]]" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 6: Multiple paths with the same sum
    {
        totalTests++;
        std::cout << "Test case 6: Multiple paths with the same sum" << std::endl;
        /*
              10
             /  \
            5    5
           / \  / \
          2   3 3  2
        */
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(2);

        int targetSum = 17;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {
            {10, 5, 2}, {10, 5, 2}
        };

        if (result.size() == 2 &&
            ((result[0] == std::vector<int>{10, 5, 2} && result[1] == std::vector<int>{10, 5, 2}) ||
             (result[0] == std::vector<int>{10, 5, 2} && result[1] == std::vector<int>{10, 5, 2}))) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected two paths: [10, 5, 2]" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 7: Deep tree with a single path
    {
        totalTests++;
        std::cout << "Test case 7: Deep tree with a single path" << std::endl;
        /*
              1
             /
            2
           /
          3
         /
        4
       /
      5
        */
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        root->left->left->left->left = new TreeNode(5);

        int targetSum = 15;

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {{1, 2, 3, 4, 5}};

        if (result == expected) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: [[1, 2, 3, 4, 5]]" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    // Test case 8: No valid paths
    {
        totalTests++;
        std::cout << "Test case 8: No valid paths" << std::endl;
        /*
              1
             / \
            2   3
           / \
          4   5
        */
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        int targetSum = 100; // No path sums to 100

        std::vector<std::vector<int> > result = solution.pathSum(root, targetSum);
        std::vector<std::vector<int> > expected = {};

        if (result == expected) {
            std::cout << "✅ Passed" << std::endl;
            testsPassed++;
        } else {
            std::cout << "❌ Failed" << std::endl;
            std::cout << "Expected: []" << std::endl;
            printPaths(result);
        }

        deleteTree(root);
    }

    std::cout << "\n===== Test Summary =====" << std::endl;
    std::cout << testsPassed << " out of " << totalTests << " tests passed." << std::endl;
}

int main() {
    testPathSum();
    return 0;
}
