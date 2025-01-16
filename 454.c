#include <stdlib.h>
#include "uthash.h"

struct HashTable {
    int _key;
    int _val;
    UT_hash_handle hh;
};

struct HashTable *hashTable;

struct HashTable *find(const int key) {
    struct HashTable *iter;
    HASH_FIND_INT(hashTable, &key, iter);
    return iter;
}

void insertOrIncrement(int key) {
    struct HashTable *iter = find(key);
    if (iter == NULL) {
        struct HashTable *newPair = malloc(sizeof(struct HashTable));
        newPair->_key = key;
        newPair->_val = 1;
        HASH_ADD_INT(hashTable, _key, newPair);
    } else {
        iter->_val++;
    }
}

int fourSumCount(int *nums1, int nums1Size, int *nums2, int nums2Size, int *nums3, int nums3Size, int *nums4,
                 int nums4Size) {
    int count = 0;
    hashTable = NULL;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            insertOrIncrement(nums1[i] + nums2[j]);
        }
    }
    for (int i = 0; i < nums3Size; i++) {
        for (int j = 0; j < nums4Size; j++) {
            struct HashTable *iter = find(-nums3[i] - nums4[j]);
            if (iter != NULL) {
                count += iter->_val;
            }
        }
    }
    return count;
}
