#include <stdio.h>
#include <string.h>

int main() {
    char str[10000] = {0};
    fgets(str, sizeof(str), stdin);
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= '0' && str[i] <= '9')
            printf("number");
        else
            putchar(str[i]);
    }
    putchar('\n');
    return 0;
}
