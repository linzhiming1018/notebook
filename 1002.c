#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **words, int wordsSize, int *returnSize) {
    int minFreq[26];
    memset(minFreq, 0x3f, sizeof(minFreq));
    for (int i = 0; i < wordsSize; i++) {
        int freq[26] = {0};
        for (int j = 0; j < strlen(words[i]); j++) {
            freq[words[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++)
            minFreq[j] = (freq[j] < minFreq[j]) ? freq[j] : minFreq[j];
    }
    *returnSize = 0; // Must be initialized before use
    for (int i = 0; i < 26; i++) {
        (*returnSize) += minFreq[i];
    }
    char **ans = (char **) malloc(sizeof(char *) * (*returnSize));
    int index = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < minFreq[i]; j++) {
            ans[index] = (char *) malloc(sizeof(char) * 2); // Trailing '\0' consumes one extra byte
            ans[index][0] = 'a' + i;
            ans[index][1] = '\0';
            index++;
        }
    }
    return ans;
}
