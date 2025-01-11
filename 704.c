#include <stdlib.h>
#include <stdio.h>

// 左闭右闭
int search1(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target < nums[mid])
            high = mid - 1;
        else if (target > nums[mid])
            low = mid + 1;
        else
            return mid;
        // Cannot "else return -1;" here.
    }
    return -1;
}

// 左闭右开
int search2(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (target < nums[mid])
            high = mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int numsSize = 5;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 5;
    nums[3] = 7;
    nums[4] = 9;

    int target = 5;
    int result = search1(nums, numsSize, target);
    printf("Index of %d: %d\n", target, result); // Expected output: Index of 5: 2

    target = 2;
    result = search1(nums, numsSize, target);
    printf("Index of %d: %d\n", target, result); // Expected output: Index of 2: -1 (not found)

    target = 9;
    result = search1(nums, numsSize, target);
    printf("Index of %d: %d\n", target, result); // Expected output: Index of 9: 4

    free(nums);
    return 0;
}