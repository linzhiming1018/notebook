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
    int numsSize = 1;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    printf("%d", search1(nums, numsSize, 9));
    return 0;
}