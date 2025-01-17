#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) {
    int capacity = 0;
    int **ans = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    // 1 <= nums.length <= 200
    if (numsSize < 4)
        return ans;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 3; ++i) {
        // Pruning
        if (nums[i] >= 0 && nums[i] > target / 4)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < numsSize - 2; ++j) {
            // Pruning
            if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target / 2)
                break;
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int l = j + 1, r = numsSize - 1;
            while (l < r) {
                long long sum_1 = nums[i] + nums[j];
                long long sum_2 = nums[l] + nums[r];
                if (sum_2 < target - sum_1) ++l;
                else if (sum_2 > target - sum_1) --r;
                else {
                    if (*returnSize == capacity) {
                        capacity += 1024;
                        ans = realloc(ans, sizeof(int *) * capacity);
                    }
                    ans[*returnSize] = malloc(sizeof(int) * 4);
                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[l];
                    ans[*returnSize][3] = nums[r];
                    (*returnSize)++;
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                }
            }
        }
    }
    if (*returnSize > 0) {
        *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for (int i = 0; i < *returnSize; i++)
            (*returnColumnSizes)[i] = 4;
    }
    return ans;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int returnSize;
    int *returnColumnSizes;
    int **ans = fourSum(nums, sizeof(nums) / sizeof(nums[0]), 0, &returnSize, &returnColumnSizes);
    free(returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}
