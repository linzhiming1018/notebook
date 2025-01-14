#include "1_wrong_answer.c"

void printAll(const int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int nums[] = {3, 3};
    int returnSize;
    int *ans = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 6, &returnSize);
    printAll(ans, returnSize);
    free(ans);
    // 清理哈希表中的所有内存
    struct HashTable *tmp;
    for (struct HashTable *s = hashTable; s != NULL; s = tmp) {
        tmp = s->hh.next;
        free(s);
    }
    return 0;
}
