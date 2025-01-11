#include <stdlib.h>
#include <stdio.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    if (n > 1)
    {
        int round = 0, step = n - 1, count = 0;
        while (round < n / 2)
        {
            // rightward
            for (int i = 0; i < step; i++)
                a[round][round + i] = ++count;
            // downward
            for (int i = 0; i < step; i++)
                a[round + i][n - 1 - round] = ++count;
            // leftward
            for (int i = 0; i < step; i++)
                a[n - 1 - round][n - 1 - round - i] = ++count;
            // upward
            for (int i = 0; i < step; i++)
                a[n - 1 - round - i][round] = ++count;
            step -= 2;
            round++;
        }
        if (n % 2 == 1)
            a[n / 2][n / 2] = ++count;
    }
    else
        a[0][0] = 1;

    return a;
}

void displayMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 3;
    int returnSize;
    int *returnColumnSizes;
    int **matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

    displayMatrix(matrix, n);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(returnColumnSizes);

    return 0;
}