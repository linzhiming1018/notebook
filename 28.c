#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate the LPS array
int *getLPS(const char *pattern) {
    int patternLength = strlen(pattern);
    int *lps = (int *) malloc(patternLength * sizeof(int));
    if (!lps) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < patternLength; i++) {
        lps[i] = 0;
    }

    int j = 0; // Length of the previous longest prefix suffix
    for (int i = 1; i < patternLength; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

// Function to find the first occurrence of 'needle' in 'haystack'
int strStr(const char *haystack, const char *needle) {
    if (!needle || strlen(needle) == 0) {
        return 0; // Empty needle
    }

    int *lps = getLPS(needle);
    int haystackLength = strlen(haystack);
    int needleLength = strlen(needle);

    int j = 0; // Index for needle
    for (int i = 0; i < haystackLength; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = lps[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == needleLength) {
            free(lps); // Free allocated memory
            return i - needleLength + 1; // Return the start index
        }
    }

    free(lps); // Free allocated memory
    return -1; // Not found
}

// Test the functions
int main() {
    const char *haystack = "hello";
    const char *needle = "ll";

    int result = strStr(haystack, needle);
    if (result != -1) {
        printf("Found at index: %d\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
