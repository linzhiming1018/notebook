#include <stdlib.h>
#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);
    int *array = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
        scanf("%d", &array[i]);
    int *prefixSum = (int *)malloc(sizeof(int) * (len + 1));
    prefixSum[0] = 0;
    for (int i = 1; i <= len; i++)
        prefixSum[i] = prefixSum[i - 1] + array[i - 1];
    int a, b;
    while (1)
    {
        if (scanf("%d %d", &a, &b) != 2)
            break;
        printf("%d\n", prefixSum[b + 1] - prefixSum[a]);
    }
    free(array);
    free(prefixSum);
    return 0;
}