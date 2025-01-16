// FILE: test_454.c

#include <stdio.h>
#include <assert.h>
#include "454.c" // Include the implementation file

void testFourSumCount() {
    // Test case 1
    int nums1[] = {1, 2};
    int nums2[] = {-2, -1};
    int nums3[] = {-1, 2};
    int nums4[] = {0, 2};
    int result = fourSumCount(nums1, 2, nums2, 2, nums3, 2, nums4, 2);
    assert(result == 2); // Expected output: 2

    // Test case 2
    int nums1_2[] = {0};
    int nums2_2[] = {0};
    int nums3_2[] = {0};
    int nums4_2[] = {0};
    result = fourSumCount(nums1_2, 1, nums2_2, 1, nums3_2, 1, nums4_2, 1);
    assert(result == 1); // Expected output: 1

    // Test case 3
    int nums1_3[] = {1, 1, -1, -1};
    int nums2_3[] = {-1, -1, 1, 1};
    int nums3_3[] = {1, -1, 0, 0};
    int nums4_3[] = {0, 0, 1, -1};
    result = fourSumCount(nums1_3, 4, nums2_3, 4, nums3_3, 4, nums4_3, 4);
    assert(result == 56); // Expected output: 56

    printf("All test cases passed!\n");
}

int main() {
    testFourSumCount();
    return 0;
}
