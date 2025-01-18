#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str, const int begin, const int end) {
    for (int i = begin, j = end - 1; i < j; ++i, --j) {
        const char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

int main() {
    int k;
    scanf("%d", &k);
    getchar();
    char *str = malloc(sizeof(char) * 10000);
    fgets(str, 10000, stdin);
    reverse(str, 0, strlen(str));
    reverse(str, 0, k);
    reverse(str, k, strlen(str));
    puts(str);
    return 0;
}
