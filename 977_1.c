#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 逐个平方，使用快速排序，时间复杂度O(NlogN)，空间复杂度O(logN)
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int a[], int low, int high)
{
    if (a == NULL || low >= high)
        return;
    int p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
        nums[i] = nums[i] * nums[i];
    quickSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}