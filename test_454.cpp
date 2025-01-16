// FILE: test_454.cpp

#include <iostream>
#include <vector>
#include "454.cpp" // Include the implementation file
#include <cassert>

void testFourSumCount() {
    Solution sol;

    // Test case 1
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-2, -1};
    std::vector<int> nums3 = {-1, 2};
    std::vector<int> nums4 = {0, 2};
    int result = sol.fourSumCount(nums1, nums2, nums3, nums4);
    assert(result == 2); // Expected output: 2

    // Test case 2
    nums1 = {0};
    nums2 = {0};
    nums3 = {0};
    nums4 = {0};
    result = sol.fourSumCount(nums1, nums2, nums3, nums4);
    assert(result == 1); // Expected output: 1

    // Test case 3
    nums1 = {1, 1, -1, -1};
    nums2 = {-1, -1, 1, 1};
    nums3 = {1, -1, 0, 0};
    nums4 = {0, 0, 1, -1};
    result = sol.fourSumCount(nums1, nums2, nums3, nums4);
    assert(result == 56); // Expected output: 56

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    testFourSumCount();
    return 0;
}
