#include <stdio.h>
#include <string.h>

void reverse(char *str, const int begin, const int end) {
    for (int i = begin, j = end - 1; i < j; ++i, --j) {
        const char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

char *reverseWords(char *s) {
    int slow = 0;
    int fast = 0;
    // Skip leading spaces
    while (fast < strlen(s) && s[fast] == ' ') {
        ++fast;
    }
    while (fast < strlen(s)) {
        if (fast > 0 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
            ++fast;
        } else {
            s[slow++] = s[fast++];
        }
    }
    // Remove trailing spaces
    if (slow > 0 && s[slow - 1] == ' ') {
        --slow;
    }
    s[slow] = '\0';
    reverse(s, 0, strlen(s));
    for (int begin = 0; begin != strlen(s);) {
        int end = begin;
        while (end < strlen(s) && s[end] != ' ') {
            ++end;
        }
        reverse(s, begin, end);
        begin = (end != strlen(s)) ? ++end : strlen(s);
    }
    return s;
}

int main() {
    char str[] = "  hello world  ";
    puts(reverseWords(str));
}
