#include <stdio.h>
#include <string.h>

void reverse(char *str, const int begin, const int end) {
    for (int i = begin, j = end - 1; i < j; i++, j--) {
        const char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

char *reverseStr(char *s, int k) {
    for (int i = 0; i < strlen(s); i += k * 2) {
        if (i + k <= strlen(s))
            reverse(s, i, i + k);
        else
            reverse(s, i, strlen(s));
    }
    return s;
}

int main() {
    char str[] = "hello";
    // The following would report "Segmentation fault". Why?
    // char *str = "hello";
    reverse(str, 0, strlen(str));
    printf("%s\n", str);
    return 0;
}
