#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int **land = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        land[i] = (int *)malloc(sizeof(int) * m);
    int *prefixSumRow = (int *)malloc(sizeof(int) * (n + 1));
    prefixSumRow[0] = 0;
    int *prefixSumCol = (int *)malloc(sizeof(int) * (m + 1));
    prefixSumCol[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &land[i][j]);
            rowSum += land[i][j];
        }
        prefixSumRow[i + 1] = prefixSumRow[i] + rowSum;
    }
    for (int i = 0; i < m; i++)
    {
        int colSum = 0;
        for (int j = 0; j < n; j++)
        {
            colSum += land[j][i];
        }
        prefixSumCol[i + 1] = prefixSumCol[i] + colSum;
    }
    // Split horizontally
    int horizontalMinDiff = 0x7fffffff;
    for (int i = 1; i < n; i++)
    {
        int diff = abs((prefixSumRow[i] - prefixSumRow[0]) - (prefixSumRow[n + 1] - prefixSumRow[i]));
        horizontalMinDiff = (diff < horizontalMinDiff) ? diff : horizontalMinDiff;
    }
    // Split vertically
    int verticalMinDiff = 0x7fffffff;
    for (int i = 1; i < m; i++)
    {
        int diff = abs((prefixSumCol[i] - prefixSumCol[0]) - (prefixSumCol[m + 1] - prefixSumRow[i]));
        verticalMinDiff = (diff < verticalMinDiff) ? diff : verticalMinDiff;
    }
    int minDiff = (horizontalMinDiff < verticalMinDiff) ? horizontalMinDiff : verticalMinDiff;
    printf("%d", minDiff);
    return 0;
}