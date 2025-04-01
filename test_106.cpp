#include "106_wrong.cpp"

class TreeTester {
    // Helper function to check if two trees are identical
    static bool areTreesEqual(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;

        return (t1->val == t2->val) &&
               areTreesEqual(t1->left, t2->left) &&
               areTreesEqual(t1->right, t2->right);
    }

    // Helper function to create a tree manually for comparison
    static TreeNode *createTree(const std::vector<int> &values) {
        if (values.empty()) return nullptr;

        auto *root = new TreeNode(values[0]);
        std::queue<TreeNode *> q;
        q.push(root);

        for (size_t i = 1; i < values.size(); i += 2) {
            TreeNode *current = q.front();
            q.pop();

            if (i < values.size() && values[i] != -1000) {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }

            if (i + 1 < values.size() && values[i + 1] != -1000) {
                current->right = new TreeNode(values[i + 1]);
                q.push(current->right);
            }
        }

        return root;
    }

    // Helper function to delete tree
    static void deleteTree(TreeNode *root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    // Helper function to print test results
    static void printTestResult(const std::string &testName, bool passed) {
        std::cout << testName << ": " << (passed ? "PASSED ✅" : "FAILED ❌") << std::endl;
    }

public:
    static void runTests() {
        Solution solution;
        int testsPassed = 0;
        int totalTests = 0;

        // Test 1: Empty tree
        {
            totalTests++;
            std::vector<int> inorder = {};
            std::vector<int> postorder = {};
            TreeNode *result = solution.buildTree(inorder, postorder);
            bool passed = result == nullptr;
            printTestResult("Test 1: Empty tree", passed);
            if (passed) testsPassed++;
        }

        // Test 2: Single node tree
        {
            totalTests++;
            std::vector<int> inorder = {1};
            std::vector<int> postorder = {1};
            TreeNode *result = solution.buildTree(inorder, postorder);
            auto *expected = new TreeNode(1);
            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 2: Single node tree", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Test 3: Complete binary tree
        {
            totalTests++;
            std::vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
            std::vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
            TreeNode *result = solution.buildTree(inorder, postorder);

            // Create expected tree: 1(2(4,5),3(6,7))
            auto *expected = new TreeNode(1);
            expected->left = new TreeNode(2);
            expected->right = new TreeNode(3);
            expected->left->left = new TreeNode(4);
            expected->left->right = new TreeNode(5);
            expected->right->left = new TreeNode(6);
            expected->right->right = new TreeNode(7);

            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 3: Complete binary tree", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Test 4: Left-skewed tree
        {
            totalTests++;
            std::vector<int> inorder = {4, 3, 2, 1};
            std::vector<int> postorder = {4, 3, 2, 1};
            TreeNode *result = solution.buildTree(inorder, postorder);

            // Create expected tree: 1(2(3(4)))
            auto *expected = new TreeNode(1);
            expected->left = new TreeNode(2);
            expected->left->left = new TreeNode(3);
            expected->left->left->left = new TreeNode(4);

            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 4: Left-skewed tree", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Test 5: Right-skewed tree
        {
            totalTests++;
            std::vector<int> inorder = {1, 2, 3, 4};
            std::vector<int> postorder = {4, 3, 2, 1};
            TreeNode *result = solution.buildTree(inorder, postorder);

            // Create expected tree: 1(,2(,3(,4)))
            auto *expected = new TreeNode(1);
            expected->right = new TreeNode(2);
            expected->right->right = new TreeNode(3);
            expected->right->right->right = new TreeNode(4);

            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 5: Right-skewed tree", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Test 6: Tree with only left children
        {
            totalTests++;
            std::vector<int> inorder = {3, 2, 1};
            std::vector<int> postorder = {3, 2, 1};
            TreeNode *result = solution.buildTree(inorder, postorder);

            // Create expected tree: 1(2(3))
            auto *expected = new TreeNode(1);
            expected->left = new TreeNode(2);
            expected->left->left = new TreeNode(3);

            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 6: Tree with only left children", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Test 7: Tree with only right children
        {
            totalTests++;
            std::vector<int> inorder = {1, 2, 3};
            std::vector<int> postorder = {3, 2, 1};
            TreeNode *result = solution.buildTree(inorder, postorder);

            // Create expected tree: 1(,2(,3))
            auto *expected = new TreeNode(1);
            expected->right = new TreeNode(2);
            expected->right->right = new TreeNode(3);

            bool passed = areTreesEqual(result, expected);
            printTestResult("Test 7: Tree with only right children", passed);
            if (passed) testsPassed++;
            deleteTree(result);
            deleteTree(expected);
        }

        // Print summary
        std::cout << "\nTest Summary: " << testsPassed << " out of " <<
                totalTests << " tests passed." << std::endl;
    }
};

int main() {
    TreeTester::runTests();
    return 0;
}
