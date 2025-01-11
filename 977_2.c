#include <stdlib.h>
#include <stdio.h>

// My Implementation
int *sortedSquares1(int *nums, int numsSize, int *returnSize)
{
    int *a = malloc(sizeof(int) * numsSize);
    int j = 0;
    while (j < numsSize && nums[j] < 0)
        j++;
    int i = j - 1, k = 0;
    while (i >= 0 && j < numsSize)
    {
        if (abs(nums[i]) <= abs(nums[j]))
        {
            a[k++] = nums[i] * nums[i];
            i--;
        }
        else
        {
            a[k++] = nums[j] * nums[j];
            j++;
        }
    }
    while (i >= 0)
    {
        a[k++] = nums[i] * nums[i];
        i--;
    }
    while (j < numsSize)
    {
        a[k++] = nums[j] * nums[j];
        j++;
    }
    *returnSize = numsSize;
    return a;
}

// Solution
int *sortedSquares2(int *nums, int numsSize, int *returnSize)
{
    int *a = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i = 0, j = numsSize - 1, k = numsSize - 1;
    while (i <= j)
    {
        if (abs(nums[i]) > abs(nums[j]))
        {
            a[k--] = nums[i] * nums[i];
            i++;
        }
        else
        {
            a[k--] = nums[j] * nums[j];
            j--;
        }
    }
    return a;
}

int main()
{
    int returnSize;
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int *result = sortedSquares2(nums, numsSize, &returnSize);

    printf("Sorted squares: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}