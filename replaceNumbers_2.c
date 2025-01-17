#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int capacity = 10000;
    char *str = malloc(sizeof(char) * capacity);
    fgets(str, capacity, stdin);
    const int oldLength = strlen(str);
    int count = 0;
    for (int i = 0; i < oldLength; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            ++count;
        }
    }
    const int newLength = oldLength + 5 * count;
    if (newLength + 1 > capacity) {
        capacity = newLength + 1;
        str = realloc(str, sizeof(char) * capacity);
    }
    str[newLength] = '\0';
    for (int i = oldLength - 1, j = newLength - 1; i >= 0; --i) {
        if (str[i] >= '0' && str[i] <= '9') {
            str[j] = 'r';
            str[j - 1] = 'e';
            str[j - 2] = 'b';
            str[j - 3] = 'm';
            str[j - 4] = 'u';
            str[j - 5] = 'n';
            j -= 6;
        } else {
            str[j] = str[i];
            --j;
        }
    }
    puts(str);
    free(str);
    return 0;
}
