#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct HashTable {
    int _key;
    int _val;
    UT_hash_handle hh;
};

struct HashTable *hashTable = NULL; // 在这里初始化哈希表为空，本地测试通过，但LeetCode判定为`Wrong Answer`

struct HashTable *find(const int key) {
    struct HashTable *iter;
    HASH_FIND_INT(hashTable, &key, iter); // 传递`key`的地址
    return iter;
}

void insert(int key, int val) {
    struct HashTable *iter = find(key);
    if (iter == NULL) {
        struct HashTable *newPair = malloc(sizeof(struct HashTable));
        newPair->_key = key;
        newPair->_val = val;
        HASH_ADD_INT(hashTable, _key, newPair);
    } else {
        iter->_val = val;
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        struct HashTable *iter = find(target - nums[i]);
        if (iter != NULL) {
            *returnSize = 2;
            int *ans = malloc(sizeof(int) * (*returnSize));
            ans[0] = iter->_val;
            ans[1] = i;
            return ans;
        } else {
            insert(nums[i], i);
        }
    }
    *returnSize = 0;
    return NULL;
}
