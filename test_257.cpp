#include "257.cpp"

// Helper function to create a tree for testing
TreeNode *createTree(std::vector<int> values, int nullValue = -1000) {
    if (values.empty()) return nullptr;

    auto *root = new TreeNode(values[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode *node = q.front();
        q.pop();

        // Left child
        if (i < values.size() && values[i] != nullValue) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != nullValue) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Helper function to free memory
void deleteTree(TreeNode *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Function to compare vectors regardless of order
bool compareVectors(const std::vector<std::string> &v1, const std::vector<std::string> &v2) {
    if (v1.size() != v2.size()) return false;

    // Create copies to sort without modifying originals
    std::vector<std::string> sorted1 = v1;
    std::vector<std::string> sorted2 = v2;

    std::sort(sorted1.begin(), sorted1.end());
    std::sort(sorted2.begin(), sorted2.end());

    return sorted1 == sorted2;
}

// Function to print vector contents for debugging
void printVector(const std::vector<std::string> &vec) {
    std::cout << "Vector contents: [";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Test function for binaryTreePaths
void testBinaryTreePaths() {
    Solution solution;
    int testCount = 0;
    int passCount = 0;

    // Test case 1: Empty tree
    {
        testCount++;
        std::cout << "Test case 1: Empty tree" << std::endl;
        TreeNode *root = nullptr;
        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << "Expected: []" << std::endl;
            printVector(result);
        }
    }

    // Test case 2: Single node tree
    {
        testCount++;
        std::cout << "Test case 2: Single node tree" << std::endl;
        auto *root = new TreeNode(1);
        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << "Expected: [\"1\"]" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 3: Simple tree (root with left and right children)
    {
        testCount++;
        std::cout << "Test case 3: Simple tree" << std::endl;
        auto *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2", "1->3"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << R"(Expected: ["1->2", "1->3"])" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 4: Left-skewed tree
    {
        testCount++;
        std::cout << "Test case 4: Left-skewed tree" << std::endl;
        auto *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2->3"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << "Expected: [\"1->2->3\"]" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 5: Right-skewed tree
    {
        testCount++;
        std::cout << "Test case 5: Right-skewed tree" << std::endl;
        auto *root = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->right = new TreeNode(3);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2->3"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << "Expected: [\"1->2->3\"]" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 6: Complex tree (LeetCode example)
    {
        testCount++;
        std::cout << "Test case 6: Complex tree" << std::endl;
        //        1
        //       / \
        //      2   3
        //       \
        //        5

        auto *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2->5", "1->3"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << R"(Expected: ["1->2->5", "1->3"])" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 7: More complex tree
    {
        testCount++;
        std::cout << "Test case 7: More complex tree" << std::endl;
        //        1
        //       / \
        //      2   3
        //     / \   \
        //    4   5   6
        //             \
        //              7

        auto *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->right = new TreeNode(6);
        root->right->right->right = new TreeNode(7);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2->4", "1->2->5", "1->3->6->7"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << R"(Expected: ["1->2->4", "1->2->5", "1->3->6->7"])" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 8: Negative numbers
    {
        testCount++;
        std::cout << "Test case 8: Negative numbers" << std::endl;
        auto *root = new TreeNode(-1);
        root->left = new TreeNode(-2);
        root->right = new TreeNode(-3);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"-1->-2", "-1->-3"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << R"(Expected: ["-1->-2", "-1->-3"])" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    // Test case 9: Multi-digit numbers
    {
        testCount++;
        std::cout << "Test case 9: Multi-digit numbers" << std::endl;
        auto *root = new TreeNode(10);
        root->left = new TreeNode(20);
        root->right = new TreeNode(30);

        std::vector<std::string> result = solution.binaryTreePaths(root);
        std::vector<std::string> expected = {"10->20", "10->30"};

        if (compareVectors(result, expected)) {
            std::cout << "PASSED" << std::endl;
            passCount++;
        } else {
            std::cout << "FAILED" << std::endl;
            std::cout << R"(Expected: ["10->20", "10->30"])" << std::endl;
            printVector(result);
        }

        deleteTree(root);
    }

    std::cout << "\nTest summary: " << passCount << " out of " << testCount << " tests passed." << std::endl;
}

int main() {
    testBinaryTreePaths();
    return 0;
}
