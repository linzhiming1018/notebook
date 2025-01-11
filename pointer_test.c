#include <stdlib.h>
#include <stdio.h>

void foo(int *p)
{
    *p = 114514;
    // p = 114514; // Wrong
}

int main()
{
    int *p = malloc(sizeof(int));
    foo(p);
    printf("%d", *p);
}