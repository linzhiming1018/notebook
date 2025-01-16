#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine) {
    int count[26] = {0};
    const char *c = magazine;
    while (*c != '\0') {
        count[*c - 'a']++;
        c++;
    }
    c = ransomNote;
    while (*c != '\0') {
        if (count[*c - 'a'] > 0)
            count[*c - 'a']--;
        else return false;
        c++;
    }
    return true;
}
