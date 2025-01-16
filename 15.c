#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int partition(int *a, int low, int high) {
    const int pivot = a[low];
    while (low < high) {
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

void quickSort(int *a, const int low, const int high) {
    if (low >= high)
        return;
    const int p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b; // Ascending order
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 1024;
    int **ans = malloc(sizeof(int *) * capacity);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else {
                if (*returnSize >= capacity) {
                    capacity += 1024;
                    ans = realloc(ans, sizeof(int *) * capacity);
                }
                ans[*returnSize] = malloc(sizeof(int) * 3);
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[j];
                ans[*returnSize][2] = nums[k];
                (*returnSize)++;
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
        }
    }
    *returnColumnSizes = malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return ans;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int *returnColumnSizes;
    int **ans = threeSum(nums, sizeof(nums) / sizeof(nums[0]), &returnSize, &returnColumnSizes);
    free(returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}
