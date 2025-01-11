#include <stdlib.h>
#include <stdio.h>

int getRightIndex(int left, int target, int *prefixSum, int numsSize)
{
    int low = left, high = numsSize - 1;
    int right = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (prefixSum[mid + 1] - prefixSum[left] < target)
            low = mid + 1;
        else
        {
            right = mid; // 找到一个符合条件的索引
            high = mid - 1;
        }
    }
    return right;
}

int minSubArrayLen(int target, int *nums, int numsSize)
{
    int *prefixSum = (int *)malloc(sizeof(int) * (numsSize + 1));
    prefixSum[0] = 0;
    for (int i = 1; i <= numsSize; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    int minLen = 0x7fffffff;
    for (int left = 0; left < numsSize; left++)
    {
        int right = getRightIndex(left, target, prefixSum, numsSize);
        // Update `minLen` if `right` is valid and length is less than `minLen`
        if (right != -1 && right - left + 1 < minLen)
            minLen = right - left + 1;
    }
    free(prefixSum);
    return minLen == 0x7fffffff ? 0 : minLen;
}

// Test function to validate the implementation
void testMinSubArrayLen()
{
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int result = minSubArrayLen(target, nums, sizeof(nums) / sizeof(nums[0]));
    printf("Test 1 - Expected: 2, Got: %d\n", result); // Subarray [4,3] or [2,3,2]

    int nums2[] = {1, 4, 4};
    target = 4;
    result = minSubArrayLen(target, nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("Test 2 - Expected: 1, Got: %d\n", result); // Subarray [4]

    int nums3[] = {1, 1, 1, 1, 1, 1};
    target = 11;
    result = minSubArrayLen(target, nums3, sizeof(nums3) / sizeof(nums3[0]));
    printf("Test 3 - Expected: 0, Got: %d\n", result); // No subarray meets the target
}

int main()
{
    testMinSubArrayLen();
    return 0;
}